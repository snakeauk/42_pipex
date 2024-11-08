/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 06:15:30 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/08 22:56:24 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputs(const char *s, int fd)
{
	int	ret;

	if (!s)
		ret = write(fd, "(nil)", 5);
	else
		ret = write(fd, s, ft_strlen(s));
	if (ret < 0)
		return (-1);
	return (ret);
}
