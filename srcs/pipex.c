/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:40:55 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/24 19:20:07 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd[2];

// 	if (argc != 5)
// 		ft_error("Error: Invalid number of arguments\n");
// 	if (pipe(fd) == -1)
// 		ft_error("Error: Failed to create pipe\n");
// 	ft_process(argc, argv, envp, fd);
// 	return (0);
// }


# define W 1
# define R 0


char	**ft_command(int argc, char **argv)
{
	char	**cmd;
	int		index;
	int		cmd_index;

	index = 2;
	cmd_index = 0;
	cmd = (char **)malloc(sizeof(char*) * (argc - 1));
	while(index < argc - 1)
		cmd[cmd_index++] = argv[index++];
	cmd[cmd_index] = NULL;
	return (cmd);
}

int main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		ret;
	int		infile;
	int		outfile;
	char	**cmd;

	if (argc < 5)
		ft_error("Error: Invalid number of arguments");
	ret = 0;
	infile = ft_fopen(argv[1], "r");
	outfile = ft_fopen(argv[argc - 1], "w");
	if (outfile < 0)
		ret = -1;
	cmd = ft_command(argc, argv);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		ft_dup2(infile, STDIN_FILENO);
		close(infile);
		ft_dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		if (ft_execute(cmd, argc - 2, envp) != NULL)
			ret = 127;
		ft_array_free(cmd);
	}
	else
	{
		close(pipe_fd[1]);
		ft_dup2(outfile, STDOUT_FILENO);
		close(outfile);
		ft_dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
	}
	return (ret);
}

