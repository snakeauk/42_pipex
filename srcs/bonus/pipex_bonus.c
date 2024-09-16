/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:04:46 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/17 07:43:51 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int 	index;
	int 	fd[2];
	int	infile;
	int	outfile;
	pid_t pid;
	char *line;

	if (argc <= 4)
		ft_error("Error: insufficient arguments\n");

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		index = 3;
		if (argc < 6)
			ft_error("Error: insufficient arguments\n");

		if (pipe(fd) == -1)
			ft_error("Error: failed to create pipe\n");

		pid = fork();
		if (pid == -1)
			ft_error("Error: failed to fork\n");

		if (pid == 0)
		{
			close(fd[0]);
			while ((line = get_next_line(0)) != NULL)
			{
				if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
					&& line[ft_strlen(argv[2])] == '\n')
				{
					free(line);
					break ;
				}
				write(fd[1], line, ft_strlen(line));
				free(line);
			}
			close(fd[1]);
			exit(0);
		}
		waitpid(pid, NULL, 0);
		close(fd[1]);
		ft_dup2(&fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	else
	{
		index = 2;
		infile = ft_fopen(argv[1], "r");
		ft_dup2(&infile, STDIN_FILENO);
		close(infile);
	}
	outfile = ft_fopen(argv[argc - 1], "w");
	while (index < argc - 2)
	{
		if (pipe(fd) == -1)
			ft_error("Error: failed to create pipe\n");

		pid = fork();
		if (pid == -1)
			ft_error("Error: Failed to fork\n");

		if (pid == 0)
		{
			ft_dup2(&fd[1], STDOUT_FILENO);
			close(fd[1]);
			close(fd[0]);
			ft_execute(argv[index], envp);
		}
		else
		{
			close(fd[1]);
			ft_dup2(&fd[0], STDIN_FILENO);
			close(fd[0]);
			waitpid(pid, NULL, 0);
		}
		index++;
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("Error: failed to redirect stdout\n");
	close(outfile);
	ft_execute(argv[argc - 2], envp);
	return (0);
}