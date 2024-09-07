/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:29:24 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/07 12:36:03 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_error(const char *format, ...)
{
	if (format != NULL)
		ft_printf(format);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}
