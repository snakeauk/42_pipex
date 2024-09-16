/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:40:55 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/17 00:33:34 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_error("Error: Invalid number of arguments\n");
	if (pipe(fd) == -1)
		ft_error("Error: Failed to create pipe\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error: Failed to fork\n");
	if (pid == 0)
		child_in(argv, envp, fd);
	close(fd[1]);
	if (waitpid(pid, NULL, 0) == -1)
		ft_error("Error: waitpid failed\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error: Failed to fork\n");
	if (pid == 0)
		child_out(argc, argv, envp, fd);
	close(fd[0]);
	if (waitpid(pid, NULL, 0) == -1)
		ft_error("Error: waitpid failed\n");
	return (0);
}
