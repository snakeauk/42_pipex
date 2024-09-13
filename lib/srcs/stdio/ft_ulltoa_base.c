/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 06:47:56 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/14 01:54:23 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ulltoa_base(unsigned long long unum, char *base)
{
	char				*ret;
	ssize_t				size;
	unsigned long long	base_len;

	base_len = (unsigned long long)ft_strlen(base);
	size = ft_ullsize(unum, base);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	while (size > 0)
	{
		ret[--size] = base[unum % base_len];
		unum /= base_len;
	}
	return (ret);
}
