/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 23:37:07 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/18 23:38:01 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_process_input(char **argv, char **envp, int *fd)
{
	int		infile;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Error: Failed to fork\n");
	if (pid == 0)
	{
		infile = ft_fopen(argv[1], "r");
		ft_dup2(infile, STDIN_FILENO);
		close(infile);
		ft_dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		ft_execute(argv[2], envp);
	}
	close(fd[1]);
	if (waitpid(pid, NULL, 0) == -1)
		ft_error("Error: waitpid failed\n");
}
