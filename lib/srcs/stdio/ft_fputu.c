/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 06:50:03 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/14 01:16:24 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputu(unsigned int unum, int fd)
{
	char	*str;
	int		ret;

	str = ft_uitoa_base(unum, BASE_10);
	if (!str)
		return (-1);
	ret = ft_fputs(str, fd);
	free(str);
	return (ret);
}
