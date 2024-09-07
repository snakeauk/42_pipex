/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:40:55 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/07 13:53:40 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		infile;
	int		outfile;

	if (argc != 5)
		ft_error("input error\n");
	if (pipe(fd) == -1)
		ft_error("");
	pid = fork();
	if (pid == -1)
		ft_error("");
	if (pid == 0)
	{
		infile  = ft_open_file(argv[1], 2);
        if (dup2(infile, STDIN_FILENO) == -1)
            ft_error("");
		ft_child_process(argv[2], envp, fd);
	}
	ft_parent_process(pid, fd);
	outfile = ft_open_file(argv[argc - 1], 1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("");
	ft_execute(argv[3], envp);
	return (0);
}
