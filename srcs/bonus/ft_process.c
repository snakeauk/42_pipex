/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:51:29 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/04 00:54:45 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_process(char *cmd, char **envp, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Error: Failed to fork\n");
	if (pid == 0)
		ft_child(cmd, envp, fd);
	close(fd[0]);
	if (waitpid(pid, NULL, 0) == -1)
		ft_error("Error: waitpid failed\n");
}
