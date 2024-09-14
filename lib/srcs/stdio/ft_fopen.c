/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:15:14 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/14 10:34:19 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fopen(char *filename, char *opt)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(opt, "wr", 2) == 0 && ft_strlen(opt) == 2)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0755);
	else if (ft_strncmp(opt, "w", 1) == 0 && ft_strlen(opt) == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	else if (ft_strncmp(opt, "r", 1) == 0 && ft_strlen(opt) == 1)
		fd = open(filename, O_RDONLY);
	else
		ft_error("Invalid file operation mode.");
	if (fd == -1)
		perror("Error opening file");
	return (fd);
}