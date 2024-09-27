/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:05:19 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/25 23:31:22 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int ft_access(char *filepath)
{
    if (access(filepath, F_OK) == 0)
    {
        if (access(filepath, X_OK) != 0)
            ft_dprintf(STDERR_FILENO, "Error: permission denied\n");
        else if (access(filepath, X_OK) == 0)
            return (0);
        return (-1);
    }
    return (-1);
}
