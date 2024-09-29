#include "ft_utils.h"

static void ft_stdin(int infile, int **pipes, int index)
{
    if (index == 0)
    {
        dup2(infile, STDIN_FILENO);
        close(infile);
    }
    else
    {
        dup2(pipes[index - 1][0], STDIN_FILENO);
        close(pipes[index - 1][0]);
    }
}

static void ft_stdout(int argc, int outfile, int **pipes, int index)
{
    if (index == argc - 4)
    {
        dup2(outfile, STDOUT_FILENO);
        close(outfile);
    }
    else
    {
        dup2(pipes[index][1], STDOUT_FILENO);
        close(pipes[index][1]);
    }
}

static int ft_file_open(int argc, char **argv, int *infile, int *outfile)
{
    int ret;

    ret = 0;
    *infile = ft_fopen(argv[1], "r");
    if (*infile < 0) // infileのエラーチェックを追加
    {
        ft_dprintf(STDERR_FILENO, "Error: Failed to open input file\n");
        ret = -1;
    }
    *outfile = ft_fopen(argv[argc - 1], "w");
    if (*outfile < 0)
    {
        ft_dprintf(STDERR_FILENO, "Error: Failed to open output file\n");
        ret = -1;
    }
    return (ret);
}

static int **ft_create_pipe(int length)
{
    int **ret;
    int index;

    ret = (int **)malloc(sizeof(int *) * length);
    if (!ret)
    {
        ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    index = 0;
    while (index < length)
    {
        ret[index] = (int *)malloc(sizeof(int) * 2);
        if (!ret[index])
        {
            ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
            ft_int_array_free(ret);
            exit(EXIT_FAILURE);
        }
        if (pipe(ret[index]) == -1)
        {
            ft_dprintf(STDERR_FILENO, "Error: Pipe creation failed\n");
            ft_int_array_free(ret);
            exit(EXIT_FAILURE);
        }
        index++;
    }
    return (ret);
}
void    ft_close_pipe(int **pipe, int length)
{
    int index;

    index = 0;
    while (index < length)
    {
        close(pipe[index][0]);
        close(pipe[index][1]);
        index++;
    }
}
// ft_pipex関数の修正
int ft_pipex(int argc, char **argv, char **env)
{
    int     ret;
    int     infile;
    int     outfile;
    int     **pipes;
    int     commands_len = argc - 3;
    int     index;
    pid_t   *pids; // 子プロセスのPIDを保存する配列

    ret = ft_file_open(argc, argv, &infile, &outfile);
    if (ret == -1)
        return (ret);
    pipes = ft_create_pipe(argc - 4);
    pids = (pid_t *)malloc(sizeof(pid_t) * commands_len);
    if (!pids)
    {
        ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
        ft_int_array_free(pipes);
        exit(EXIT_FAILURE);
    }

    index = 0;
    while (index < commands_len)
    {
        pids[index] = fork();
        if (pids[index] == -1)
        {
            ft_dprintf(STDERR_FILENO, "Error: Fork failed\n");
            exit(EXIT_FAILURE);
        }
        if (pids[index] == 0)
        {
            // 子プロセス内での処理
            ft_stdin(infile, pipes, index);
            ft_stdout(argc, outfile, pipes, index);

            // 子プロセスは不要なパイプをすべて閉じる
            ft_close_pipe(pipes, argc - 4);
            ft_int_array_free(pipes);

            ft_execute(argv[2 + index], env);
            exit(EXIT_FAILURE); // ft_executeが戻ってきた場合はエラー
        }
        index++;
    }

    // 親プロセスは不要なパイプをすべて閉じる
    ft_close_pipe(pipes, argc - 4);
    ft_int_array_free(pipes);

    // 子プロセスの終了を待つ
    index = 0;
    while (index < commands_len)
    {
        waitpid(pids[index], NULL, 0);
        index++;
    }
    free(pids);

    return (ret);
}