/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:15:14 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/30 02:49:22 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fopen(char *filename, const char *mode)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(mode, "w", 1) == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strncmp(mode, "a", 1) == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (ft_strncmp(mode, "r", 1) == 0)
		fd = open(filename, O_RDONLY);
	else
		ft_dprintf(STDERR_FILENO, "Invalid file operation mode.\n");
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
