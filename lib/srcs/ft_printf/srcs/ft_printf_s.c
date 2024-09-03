/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 03:04:54 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 22:03:14 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(t_args *args)
{
	int		ret;
	char	*str;

	ret = 0;
	str = va_arg(args->ap, char *);
	if (str == NULL)
		str = "(null)";
	if (!str)
	{
		args->error_flag++;
		return (ret);
	}
	ret += ft_outstr(str);
	return (ret);
}
