/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:38:18 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/14 11:38:19 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_exit(int status, char *message)
{
	ft_dprintf(STDERR_FILENO, message);
	ft_dprintf(STDERR_FILENO, "\n");
	exit(status);
}
