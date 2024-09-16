/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:04:46 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/17 07:36:01 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int 	index;
	int 	fd[2];
	int outfile;

	if (argc <= 4)
		ft_error("Error: insufficient arguments\n");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_here_doc(argv[2], argc);
		index = 3;
	}
	else
	{
		child_in(argv, envp, fd);
		index = 2;
	}
	outfile = ft_fopen(argv[argc - 1], "w");
	while (index < argc - 2)
	{
		ft_process(argv[index], envp, fd);
		index++;
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("Error: failed to redirect stdout\n");
	close(outfile);
	ft_execute(argv[argc - 2], envp);
	return (0);
}