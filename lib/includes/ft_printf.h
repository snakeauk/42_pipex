/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 03:07:06 by kinamura          #+#    #+#             */
/*   Updated: 2024/08/13 14:57:07 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BASE_10 "0123456789"
# define BASE_LOW_16 "0123456789abcdef"
# define BASE_TOP_16 "0123456789ABCDEF"

typedef struct s_args
{
	va_list	ap;
	char	*fmt;
	size_t	index;
	int		length;
	int		error_flag;
}			t_args;

int			ft_printf(const char *format, ...);
void		ft_vprintf(t_args *args);
int			ft_outchar(char c);
int			ft_outstr(const char *str);
void		ft_printf_type(t_args *args);
int			ft_printf_c(t_args *args);
int			ft_printf_s(t_args *args);
int			ft_printf_p(t_args *args);
int			ft_printf_d(t_args *args);
int			ft_printf_i(t_args *args);
int			ft_printf_u(t_args *args);
int			ft_printf_x(t_args *args);
int			ft_printf_large_x(t_args *args);
int			ft_putnbr_base(long long num, char *base);
int			ft_putunbr_base(unsigned long long num, char *base);

#endif