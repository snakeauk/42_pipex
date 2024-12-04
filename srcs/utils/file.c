/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:24 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/05 02:26:43 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	open_infile(t_pipe *data);
int	open_outfile(t_pipe *data);
int open_iofile(t_pipe *data);

int	open_infile(t_pipe *data)
{
	if (is_here_doc(data->argv))
	{
		if (here_doc(data->argv[2], data) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	else
		data->infile = ft_fopen(data->argv[1], "r");
	if (data->infile < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	open_outfile(t_pipe *data)
{
	if (is_here_doc(data->argv))
		data->outfile = ft_fopen(data->argv[data->argc - 1], "a");
	else
		data->outfile = ft_fopen(data->argv[data->argc - 1], "w");
	if (data->outfile < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int open_iofile(t_pipe *data)
{
	open_infile(data);
	if (data->infile < 0)
		return (EXIT_FAILURE);
	open_outfile(data);
	if (data->outfile < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
