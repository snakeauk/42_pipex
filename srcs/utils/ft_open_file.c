/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:15:14 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/02 22:13:06 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_open_file(char *filename, int opt)
{
	int	fd;

	fd = 0;
	if (opt == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (opt == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (opt == 2)
		fd = open(filename, O_RDONLY, 0777);
	if (fd == -1)
		ft_error();
	return (fd);
}
