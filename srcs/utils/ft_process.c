/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 23:37:07 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/25 15:41:06 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

// void	ft_process(int argc, char **argv, char **envp, int *fd)
// {
// 	int		infile;
// 	int		outfile;
// 	pid_t	pid;

// 	infile = ft_fopen(argv[1], "r");
// 	outfile = ft_fopen(argv[argc - 1], "w");
// 	pid = fork();
// 	if (pid == -1)
// 		ft_error("Error: Failed to fork\n");
// 	if (pid == 0)
// 		ft_process_child(argv[2], envp, fd, infile);
// 	else
// 	{
// 		close(fd[1]);
// 		if (waitpid(pid, NULL, 0) == -1)
// 			ft_error("Error: waitpid failed\n");
// 		ft_process_parent(argv[argc - 2], envp, fd, outfile);
// 	}
// }
