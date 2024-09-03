/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:02:06 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 22:03:22 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int			sign;
	long long	num;

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
		if (sign == 1 && ((LLONG_MAX - (*str - '0')) / 10 < num))
			return (LLONG_MAX);
		else if (sign == -1 && ((LLONG_MIN + (*str - '0')) / 10 > -num))
			return (LLONG_MIN);
		num = 10 * num + (*str - '0');
		str++;
	}
	return (sign * num);
}
