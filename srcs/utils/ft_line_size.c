/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:03:03 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/06 00:01:26 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_read_size(int fd, char **line)
{
	char	*buf;
	ssize_t read_bytes;
	ssize_t	size;

	buf = malloc(sizeof(char) * READ_SIZE);
	if (!buf)
		return (-1);
	read_bytes = 1;
	size = 0;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buf, READ_SIZE);
		if (read_bytes < 0)
			return (-1);
		if (buf)
		{
			if (ft_strchr(buf, '\n'))
				break ;
		}
		*line = ft_memadd(*line, (const char *)buf, read_bytes);
		if (!line)
			return (-1);
		size += read_bytes;
		free(buf);
	}
	return ((int)size);
}
