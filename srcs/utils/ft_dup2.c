/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:34:18 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/17 00:34:30 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_dup2(int *fildes, int fildes2)
{
	int	ret;

	ret = dup2(*fildes, fildes2);
	if (ret < 0)
		ft_error("Error: Failed to redirect file descriptor\n");
	return (ret);
}
