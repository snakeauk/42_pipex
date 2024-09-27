/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 23:36:53 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/22 22:44:48 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int 	index;
	int 	fd[2];
	int 	outfile;

	if (argc <= 4)
		ft_error("Error: insufficient arguments\n");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		index = 3;
		ft_here_doc(argv[2], argc, fd);
	}
	else
	{
		index = 2;
		ft_process(argc, argv, envp, fd);
	}
	// while (index < argc - 2)
	// {
	// 	pid = fork();
	// 	if (pid == -1)
	// 		ft_error("Error: Failed to fork\n");
	// 	if (pid == 0)
	// 	{
	// 		ft_dup2(fd[0], STDIN_FILENO);
	// 		ft_dup2(fd[1], STDOUT_FILENO);
	// 		ft_execute(argv[index], envp);
	// 		close(fd[1]);
	// 	}
	// 	close(fd[0]);
	// 	if (waitpid(pid, NULL, 0) == -1)
	// 		ft_error("Error: waitpid failed\n");
	// 	index++;
	// }
	ft_process_output(index+1/*argc - 1*/, argv, envp, fd);
	return (0);
}