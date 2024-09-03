/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:03:49 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/04 01:03:50 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_error_message(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}
