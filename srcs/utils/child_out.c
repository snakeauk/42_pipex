/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:34:47 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/17 00:41:10 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	child_out(int argc, char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = ft_fopen(argv[argc - 1], "w");
	if (outfile < 0)
		ft_error("Error: Failed to open output file\n");
	ft_dup2(&fd[0], STDIN_FILENO);
	close(fd[0]);
	ft_dup2(&outfile, STDOUT_FILENO);
	close(outfile);
	ft_execute(argv[3], envp);
}
