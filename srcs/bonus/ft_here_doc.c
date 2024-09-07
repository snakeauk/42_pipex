/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:31 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/07 13:58:25 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_error("");
	if (pipe(fd) == -1)
		ft_error("");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		line = get_next_line(1);
		while (line)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && line[ft_strlen(limiter)] == '\n')
				break;
			write(fd[1], line, ft_strlen(line));
			line = get_next_line(1);
		}
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
            ft_error("");
		wait(NULL);
	}
}
