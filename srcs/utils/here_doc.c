/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:40 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/09 23:00:23 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		is_here_doc(char **argv);
char	*read_line(char *limit);
int		write_fd(int fd, char *limit);
int		here_doc(char *limit, t_pipe *data);

int	is_here_doc(char **argv)
{
	return (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8);
}

char	*read_line(char *limit)
{
	char	*line;
	char	*str;

	str = NULL;
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		if (get_next_line(STDIN_FILENO, &line) <= 0)
		{
			free(str);
			free(line);
			return (NULL);
		}
		if (ft_strlen(line) - 1 == ft_strlen(limit)
			&& (!ft_strncmp(limit, line, ft_strlen(limit))))
			break ;
		ft_stradd(&str, line);
		free(line);
	}
	free(line);
	return (str);
}

int	write_fd(int fd, char *limit)
{
	char	*str;

	str = read_line(limit);
	if (!str)
		return (EXIT_FAILURE);
	if (ft_fputs(str, fd) < 0)
	{
		perror("Error writing to file");
		free(str);
		return (EXIT_FAILURE);
	}
	free(str);
	return (EXIT_SUCCESS);
}

int	here_doc(char *limit, t_pipe *data)
{
	int		fd;

	fd = ft_fopen(HEREDOC_TMP_FILE, "w");
	if (fd <= 0)
		return (EXIT_FAILURE);
	if (write_fd(fd, limit) != EXIT_SUCCESS)
	{
		unlink(HEREDOC_TMP_FILE);
		return (EXIT_FAILURE);
	}
	if (ft_close(fd) < 0)
		return (EXIT_FAILURE);
	data->infile = ft_fopen(HEREDOC_TMP_FILE, "r");
	if (data->infile <= 0)
	{
		unlink(HEREDOC_TMP_FILE);
		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}
