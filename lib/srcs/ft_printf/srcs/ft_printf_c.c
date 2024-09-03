/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 03:04:34 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 22:03:03 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(t_args *args)
{
	int		ret;
	char	c;

	ret = 0;
	c = va_arg(args->ap, int);
	ret += ft_outchar(c);
	if (ret == -1)
		args->error_flag++;
	return (ret);
}
