/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:34:47 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/18 22:21:57 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_process_output(int index, char **argv, char **envp, int *fd)
{
	int		outfile;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Error: Failed to fork\n");
	if (pid == 0)
	{
		outfile = ft_fopen(argv[index], "w");
		if (outfile < 0)
			ft_error("Error: Failed to open output file\n");
		ft_dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		ft_dup2(outfile, STDOUT_FILENO);
		close(outfile);
		ft_execute(argv[3], envp);
	}
	close(fd[0]);
	if (waitpid(pid, NULL, 0) == -1)
		ft_error("Error: waitpid failed\n");
}
