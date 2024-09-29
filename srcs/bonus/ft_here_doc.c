/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:31 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/29 13:53:22 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(char *limiter, int argc, int **pipe)
{
	pid_t pid;
	char *line;

	if (argc < 6)
		ft_error("Error: insufficient arguments\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error: failed to fork\n");
	if (pid == 0)
	{
		close(pipe[0][0]);
		while ((line = get_next_line(0)) != NULL)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
				&& line[ft_strlen(limiter)] == '\n')
			{
				free(line);
				break ;
			}
			if (write(pipe[0][1], line, ft_strlen(line)) == -1)
			{
				free(line);
				close(pipe[1]);
				ft_error("Error: failed to write to pipe\n");
			}
			free(line);
		}
		close(pipe[0][1]);
		exit(0);
	}
}