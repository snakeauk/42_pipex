/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:15:14 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/12 05:34:33 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_open_file(char *filename, int opt)
{
	int	fd;

	fd = 0;
	if (opt == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0755);
	else if (opt == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	else if (opt == 2)
		fd = open(filename, O_RDONLY, 0755);
	if (fd == -1)
		perror("Error");
	return (fd);
}
