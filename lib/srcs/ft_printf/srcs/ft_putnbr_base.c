/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 03:05:09 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 22:03:14 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long num, char *base)
{
	int			ret;
	long long	base_len;

	ret = 0;
	base_len = (long long)ft_strlen(base);
	if (num < 0)
	{
		ret += ft_outchar('-');
		num *= -1;
	}
	if (num >= base_len)
		ret += ft_putnbr_base(num / base_len, base);
	ret += ft_outchar(base[num % base_len]);
	return (ret);
}
// #include <stdio.h>
// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
//     int num = ft_atoi(av[1]);
//     printf("ft_putnbr_base:%d", ft_putnbr_base(num, "0123456789"));
//     return (0);
// }