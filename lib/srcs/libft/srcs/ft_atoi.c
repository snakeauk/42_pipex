/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:46:18 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 22:03:14 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	ln;
	int			sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	ln = 0;
	while (ft_isdigit(*str))
	{
		if (sign == 1 && ((LONG_MAX - (*str - '0')) / 10 < ln))
			return ((int)LONG_MAX);
		else if (sign == -1 && ((LONG_MIN + (*str - '0')) / 10 > -ln))
			return ((int)LONG_MIN);
		ln = 10 * ln + (*str - '0');
		str++;
	}
	return (sign * (int)ln);
}
