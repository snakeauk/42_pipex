/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:54:25 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/27 23:35:04 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_execute(char *command, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	if (!cmd || !cmd[0])
	{
		ft_array_free(cmd);
		ft_error("Error: command parsing failed\n");
		return ;
	}
	path = ft_get_path(cmd[0], envp);
	if (!path)
	{
		ft_error("%s : command not found\n", cmd[0]);
		ft_array_free(cmd);
		return ;
	}
	if (execve(path, cmd, envp) == -1)
		perror("Error: permission denied");
	ft_array_free(cmd);
	free(path);
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
void ft_pipex(int argc, char **argv, char **envp)
{
    int     infile;
    int     outfile;
    int     **pipes;
    pid_t   *child_pids;
    int     num_commands;
    int     num_pipes;
    int     index;

    num_commands = argc - 3;
    num_pipes = num_commands - 1;

    // パイプと子プロセスIDの配列を作成
    pipes = ft_create_pipe(num_pipes);
    if (!pipes)
        ft_error("Error: Pipe creation failed");

    child_pids = malloc(sizeof(pid_t) * num_commands);
    if (!child_pids)
        ft_error("Error: Memory allocation failed");

    // ファイルのオープンとエラーチェック
    infile = ft_fopen(argv[1], "r");
    if (infile == -1)
        ft_error("Error: Failed to open input file");

    outfile = ft_fopen(argv[argc - 1], "w");
    if (outfile == -1)
        ft_error("Error: Failed to open output file");

    index = 0;
    while (index < num_commands)
    {
        pid_t pid = fork();
        if (pid == -1)
            ft_error("Error: Fork failed");

        if (pid == 0)
        {
            // 子プロセス内
            ft_infile(infile, pipes, index);
            ft_outfile(argc, outfile, pipes, index);
            ft_close_unused_pipes(pipes, num_pipes, index);
    		ft_close_all_pipes(pipes, num_pipes);
            if (ft_execute(argv[2 + index], envp) == -1)
                exit(EXIT_FAILURE);
            exit(EXIT_SUCCESS);
        }
        else
        {
            // 親プロセス内
            child_pids[index] = pid;
        }
        index++;
    }

    // 親プロセスで全てのパイプをクローズ
    ft_close_all_pipes(pipes, num_pipes);

    // 全ての子プロセスを待機
    index = 0;
    while (index < num_commands)
    {
        int status;
        waitpid(child_pids[index], &status, 0);
        index++;
    }

    free(child_pids);
    close(infile);
    close(outfile);
}
