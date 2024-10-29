/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:51:26 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/30 02:51:28 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_iodup(int infile, int outfile)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		return (ERROR);
	if (infile != STDIN_FILENO)
	{
		if (close(infile) < 0)
			return (ERROR);
	}
	if (dup2(outfile, STDOUT_FILENO) < 0)
		return (ERROR);
	if (outfile != STDOUT_FILENO)
	{
		if (close(outfile) < 0)
			return (ERROR);
	}
	return (0);
}
