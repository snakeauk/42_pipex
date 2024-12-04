/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:24 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/04 22:57:29 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	file_open(int argc, char **argv, t_pipe *data);

int	file_open(int argc, char **argv, t_pipe *data)
{
	int	status;

	status = EXIT_SUCCESS;
	if (is_here_doc(argv))
	{
		data->outfile = ft_fopen(argv[argc - 1], "a");
		status = here_doc(argv[2], data);
	}
	else
	{
		data->outfile = ft_fopen(argv[argc - 1], "w");
		data->infile = ft_fopen(argv[1], "r");
	}
	if (data->infile < 0 || status == EXIT_FAILURE)
	{
		if (data->outfile < 0)
			close(data->outfile);
		return (EXIT_FAILURE);
	}
	if (data->outfile < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
