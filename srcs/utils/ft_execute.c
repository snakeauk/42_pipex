#include "ft_utils.h"

void	ft_execute(char *command, char **envp)
{
    char	**cmd;
    char	*path;

    cmd = ft_split(command, ' ');
    if (!cmd || !cmd[0])
    {
        ft_array_free(cmd);
        perror("Error: command parsing failed");
        exit(EXIT_FAILURE);
    }
    path = ft_get_path(cmd[0], envp);
    if (!path)
    {
        fprintf(stderr, "%s: command not found\n", cmd[0]);
        ft_array_free(cmd);
        exit(EXIT_FAILURE);
    }
    if (execve(path, cmd, envp) == -1)
    {
        perror("Error");
        ft_array_free(cmd);
        free(path);
        exit(EXIT_FAILURE);
    }
}

int **ft_create_pipe(int count)
{
    int index;
    int **ret;

    ret = (int **)malloc(sizeof(int *) * count);
    if (!ret)
        return (NULL);
    for (index = 0; index < count; index++)
    {
        ret[index] = (int *)malloc(sizeof(int) * 2);
        if (!ret[index])
        {
            while (--index >= 0)
                free(ret[index]);
            free(ret);
            return (NULL);
        }
        if (pipe(ret[index]) == -1)
        {
            while (index >= 0)
            {
                free(ret[index]);
                index--;
            }
            free(ret);
            ft_error("Error: Pipe creation failed\n");
            return (NULL);
        }
    }
    return (ret);
}

void	ft_close_pipe(int **pipes, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		close(pipes[index][0]);
		close(pipes[index][1]);
		index++;
	}
}

void	ft_outfile(int argc, int outfile, int **pipes, int index)
{
	if (index == argc - 4)
	{
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
	else
		dup2(pipes[index][1], STDOUT_FILENO);
}

void	ft_infile(int infile, int **pipes, int index)
{
	if (index == 0)
	{
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	else
		dup2(pipes[index - 1][0], STDIN_FILENO);
}

// void	ft_pipex(int argc, char **argv, char **envp)
// {
// 	int		infile;
// 	int		outfile;
//     int     **pipes;
//     pid_t   pid;
// 	int		index;

// 	pipes = ft_create_pipe(argc - 4);
// 	infile = ft_fopen(argv[1], "r");
//     outfile = ft_fopen(argv[argc - 1], "w");
// 	index = 0;
//     while (index < argc - 3)
//     {
//         pid = fork();
//         if (pid == -1)
//             ft_error("Error: Fork failed");
//         if (pid == 0)
//         {
// 			ft_infile(infile, pipes, index);
// 			ft_outfile(argc, outfile, pipes, index);
// 			ft_close_pipe(pipes, argc - 4);
//             ft_execute(argv[2 + index], envp);
//             exit(EXIT_FAILURE);
//         }
// 		else
// 		{
// 			ft_close_pipe(pipes, argc - 4);
//         	wait(NULL);
// 		}
// 		index++;
//     }
// }
void    ft_execute_all(int argc, char **argv, char **envp)
{
    int     num_commands = argc - 3; // コマンドの数
    int     num_pipes = num_commands - 1; // 必要なパイプの数
    int     pipes[num_pipes][2];
    pid_t   pid;

    // パイプの作成
    for (int i = 0; i < num_pipes; i++)
    {
        if (pipe(pipes[i]) == -1)
            ft_error("Error: Pipe creation failed\n");
    }

    // コマンドの実行
    for (int i = 0; i < num_commands; i++)
    {
        pid = fork();
        if (pid == -1)
            ft_error("Error: Fork failed");
        if (pid == 0)
        {
            // 入力の設定
            if (i == 0)
            {
                // 最初のコマンド
                int infile = ft_fopen(argv[1], "r");
                if (infile < 0)
                    ft_error("Error: Can't open infile");
                dup2(infile, STDIN_FILENO);
                close(infile);
            }
            else
            {
                // 前のパイプから読み込む
                dup2(pipes[i - 1][0], STDIN_FILENO);
            }

            // 出力の設定
            if (i == num_commands - 1)
            {
                // 最後のコマンド
                int outfile = ft_fopen(argv[argc - 1], "w");
                if (outfile < 0)
                    ft_error("Error: Can't open outfile");
                dup2(outfile, STDOUT_FILENO);
                close(outfile);
            }
            else
            {
                // 次のパイプに書き込む
                dup2(pipes[i][1], STDOUT_FILENO);
            }

            // 不要なパイプを閉じる
            for (int j = 0; j < num_pipes; j++)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            // コマンドの実行
            ft_execute(argv[2 + i], envp);
            exit(EXIT_FAILURE);
        }
    }

    // 親プロセスでのパイプのクローズと子プロセスの待機
    for (int i = 0; i < num_pipes; i++)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
    for (int i = 0; i < num_commands; i++)
    {
        wait(NULL);
    }
}