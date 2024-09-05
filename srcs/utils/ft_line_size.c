/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:03:03 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 21:59:52 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	*ft_read_size(char **line)
{
	char	*buf;
	ssize_t read_bytes;
	ssize_t	size;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	read_bytes = 1;
	size = 0;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buf), free(str), -1);
		if (buf)
		{
			if (ft_strchr(buf, '\n'))
				break ;
		}
		*line = ft_memadd(*line, (const char *)buf, read_bytes);
		if (!line)
			return (free(buf), -1);
		size += read_bytes;
	}
	free(buf);
	return ((int)size);
}

int	ft_line_size(char **line)
{
	char	*buf;
	int		index;
	ssize_t	read_bytes;
	char	c;

	index = 0;
	read_bytes = 0;
	buf = (char *)malloc(10000);
	if (!buf)
		return (-1);
	read_bytes = read(0, &c, 1);
	while (read_bytes && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buf[index] = c;
		index++;
		read_bytes = read(0, &c, 1);
	}
	buf[index] = '\n';
	index++;
	buf[index] = '\0';
	*line = buf;
	return (read_bytes);
}
