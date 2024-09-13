/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:07:03 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/10 12:07:04 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	num;

	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	num = 0;
	while (ft_isdigit(*str))
	{
		if (sign == 1 && ((LONG_MAX - (*str - '0')) / 10 < num))
			return (LONG_MAX);
		else if (sign == -1 && ((LONG_MIN + (*str - '0')) / 10 > -num))
			return (LONG_MIN);
		num = 10 * num + (*str - '0');
		str++;
	}
	return (sign * num);
}
