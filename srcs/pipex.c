/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:40:55 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/04 01:45:06 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(int outfile, char *cmd, char **envp, int *fd)
{
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	ft_execute(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		infile;
	int		outfile;

	if (argc != 5)
		ft_error();
	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
	{
		infile  = ft_open_file(argv[1], 2);
		dup2(infile, STDIN_FILENO);
		ft_child_process(argv[2], envp, fd);
	}
	waitpid(pid, NULL, 0);
	outfile = ft_open_file(argv[4], 1);
	ft_parent_process(outfile, argv[3], envp, fd);
	return (0);
}
