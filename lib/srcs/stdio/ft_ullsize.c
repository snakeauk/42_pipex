/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 06:48:39 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/14 01:55:26 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ullsize(unsigned long long unum, char *base)
{
	int		ret;
	size_t	base_len;

	base_len = ft_strlen(base);
	ret = 0;
	if (unum == 0)
		return (1);
	while (unum != 0)
	{
		unum /= (unsigned long long)base_len;
		ret++;
	}
	return (ret);
}
