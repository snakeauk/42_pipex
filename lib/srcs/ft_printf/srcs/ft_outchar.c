/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 03:04:38 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 22:02:48 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_outchar(const char c)
{
	int	ret;

	ret = 0;
	ret += write(1, &c, 1);
	return (ret);
}
// #include <stdio.h>
// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return (0);
//     char c = av[1][0];
//     printf("%d", ft_outchar(c));
//     return (0);
// }