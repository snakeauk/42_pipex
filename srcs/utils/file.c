/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:24 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/10 21:17:04 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	open_iofile(t_pipe *data, int *pipefd);

static int	open_infile(t_pipe *data)
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

static int	open_outfile(t_pipe *data)
{
	if (is_here_doc(data->argv))
		data->outfile = ft_fopen(data->argv[data->argc - 1], "a");
	else
		data->outfile = ft_fopen(data->argv[data->argc - 1], "w");
	if (data->outfile < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	open_iofile(t_pipe *data, int *pipefd)
{
	if (data->cmd_index == 0)
	{
		open_infile(data);
		if (data->infile < 0)
		{
			close_pipes(pipefd, data);
			return (EXIT_FAILURE);
		}
	}
	else if (data->cmd_index == data->cmd_size - 1)
	{
		open_outfile(data);
		if (data->outfile < 0)
		{
			close_pipes(pipefd, data);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
