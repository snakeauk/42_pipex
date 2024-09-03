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
