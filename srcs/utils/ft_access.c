/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:05:19 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/20 00:14:05 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int ft_access(char *path)
{
    if (access(path, F_OK) == 0 && access(path, X_OK) != 0)
        ft_error("Error: permission denied\n");
    else if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
        return (0);
    return (-1);
}