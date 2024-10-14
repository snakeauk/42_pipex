/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:39:13 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/14 11:40:15 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static void	ft_stdin(char **argv, int **pipes, int index)
{
	int	infile;

	if (index == 0)
	{
		infile = ft_fopen(argv[1], "r");
		if (infile < 0)
			exit(EXIT_FAILURE);
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	else
	{
		dup2(pipes[index - 1][0], STDIN_FILENO);
		close(pipes[index - 1][0]);
	}
}

static void	ft_stdout(int argc, char **argv, int **pipes, int index)
{
	int	outfile;

	if (index == argc - 4)
	{
		outfile = ft_fopen(argv[argc - 1], "w");
		if (outfile < 0)
			exit(EXIT_FAILURE);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
	else
	{
		dup2(pipes[index][1], STDOUT_FILENO);
		close(pipes[index][1]);
	}
}

void	ft_stdio(int argc, char **argv, int **pipes, int index)
{
	ft_stdin(argv, pipes, index);
	ft_stdout(argc, argv, pipes, index);
}
