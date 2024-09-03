/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 03:05:03 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 21:56:28 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type(t_args *args)
{
	if (args->fmt[args->index] == 'c')
		args->length += ft_printf_c(args);
	else if (args->fmt[args->index] == 's')
		args->length += ft_printf_s(args);
	else if (args->fmt[args->index] == 'p')
		args->length += ft_printf_p(args);
	else if (args->fmt[args->index] == 'd')
		args->length += ft_printf_d(args);
	else if (args->fmt[args->index] == 'i')
		args->length += ft_printf_i(args);
	else if (args->fmt[args->index] == 'u')
		args->length += ft_printf_u(args);
	else if (args->fmt[args->index] == 'x')
		args->length += ft_printf_x(args);
	else if (args->fmt[args->index] == 'X')
		args->length += ft_printf_large_x(args);
	else if (args->fmt[args->index] == '%')
		args->length += ft_outchar('%');
}

void	ft_printf_format(t_args *args)
{
	while (args->fmt[args->index])
	{
		if (args->fmt[args->index] == '%')
		{
			args->index++;
			ft_printf_type(args);
		}
		else
			args->length += ft_outchar(args->fmt[args->index]);
		args->index++;
	}
}

void	ft_vprintf(t_args *args)
{
	if (!ft_strchr(args->fmt, '%'))
	{
		ft_outstr(args->fmt);
		args->length = ft_strlen(args->fmt);
		return ;
	}
	ft_printf_format(args);
}

int	ft_printf(const char *format, ...)
{
	t_args	*args;
	int		ret;

	if (!format)
		return (-1);
	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (-1);
	args->length = 0;
	args->index = 0;
	args->error_flag = 0;
	args->fmt = (char *)format;
	va_start(args->ap, format);
	ft_vprintf(args);
	va_end(args->ap);
	ret = args->length;
	if (args->error_flag != 0)
		ret = -1;
	free(args);
	return (ret);
}
// #include <stdio.h>
// int main (void)
// {
//     char *s = "ft_printf:";
//     char *line = "======\n======\n";
//     while (*line)
//     {
//         write(1, line, 1);
//         line++;
//     }
//     while (*s)
//     {
//         write(1, s, 1);
//         s++;
//     }
//     int ft_ret;
//     ft_ret = ft_printf(" %c %c %c ", 0, '1', '2');
//     printf(":::\n");
//     printf("   printf:");
// /*-------------------------------------------*/
//     int ret;
//     ret = printf(" %c %c %c ", 0, '1', '2');
// /*-------------------------------------------*/
//     printf(":::\n");
//     printf("ft_printf:%d\n", ft_ret);
//     printf("   printf:%d\n", ret);
//     return (0);
// }