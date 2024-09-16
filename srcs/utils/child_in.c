/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:35:22 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/17 00:41:01 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	child_in(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = ft_fopen(argv[1], "r");
	ft_dup2(&infile, STDIN_FILENO);
	close(infile);
	ft_dup2(&fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	ft_execute(argv[2], envp);
}
