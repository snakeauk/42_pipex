/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:31 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/14 17:08:30 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(char *limiter, int argc)
{
	pid_t pid;
	int fd[2];
	char *line;

	if (argc < 6)
		ft_error("Error: insufficient arguments\n");
	if (pipe(fd) == -1)
		ft_error("Error: failed to create pipe\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error: failed to fork\n");
	if (pid == 0)
	{
		close(fd[0]);
		while ((line = get_next_line(1)) != NULL)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
				&& line[ft_strlen(limiter)] == '\n')
			{
				free(line);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error("Error: failed to redirect stdin\n");
		wait(NULL);
		close(fd[0]);
	}
}