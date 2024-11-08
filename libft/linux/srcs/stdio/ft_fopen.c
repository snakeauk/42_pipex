/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:15:14 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/08 23:06:46 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_fopen(char *filename, const char *mode)
{
	int	fd;

	fd = -1;
	if (ft_strncmp(mode, "w", 1) == 0 && ft_strlen(mode) == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strncmp(mode, "wr", 2) == 0 && ft_strlen(mode) == 2)
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (ft_strncmp(mode, "a", 1) == 0 && ft_strlen(mode) == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (ft_strncmp(mode, "r", 1) == 0 && ft_strlen(mode) == 1)
		fd = open(filename, O_RDONLY);
	else
		ft_dprintf(STDERR_FILENO, "Invalid file operation mode.\n");
	if (fd < 0)
		ft_dprintf(STDERR_FILENO, "%s: No such file or directory\n", filename);
	return (fd);
}
