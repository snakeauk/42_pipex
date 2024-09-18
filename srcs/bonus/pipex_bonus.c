/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:04:46 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/18 21:50:51 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// static void	handle_here_doc(char **argv, int fd[2])
// {
// 	char	*line;

// 	if (pipe(fd) == -1)
// 		ft_error("Error: failed to create pipe");
// 	pid_t pid = fork();
// 	if (pid == -1)
// 		ft_error("Error: failed to fork");
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		while ((line = get_next_line(STDIN_FILENO)))
// 		{
// 			if (strncmp(line, argv[2], strlen(argv[2])) == 0 && line[strlen(argv[2])] == '\n')
// 			{
// 				free(line);
// 				break;
// 			}
// 			write(fd[1], line, strlen(line));
// 			free(line);
// 		}
// 		close(fd[1]);
// 		exit(0);
// 	}
// 	close(fd[1]);
// 	ft_dup2(&fd[0], STDIN_FILENO);
// 	if (waitpid(pid, NULL, 0) == -1)
// 		ft_error("Error: waitpid failed");
// 	close(fd[0]);
// }

// void	ft_child_in(char **argv, char **envp, int fd[2])
// {
// 	int input_fd = open(argv[1], O_RDONLY);
// 	if (input_fd == -1)
// 		ft_error("Error: failed to open input file");
// 	ft_dup2(&input_fd, STDIN_FILENO);
// 	ft_dup2(&fd[1], STDOUT_FILENO);
// 	close(fd[0]);
// 	close(input_fd);
// 	execve(argv[2], &argv[2], envp);
// 	ft_error("Error: execve failed");
// }

// void	ft_child_out(int idx, char **argv, char **envp, int fd[2])
// {
// 	// Define behavior for subsequent child processes
// 	ft_dup2(&fd[0], STDIN_FILENO);
// 	close(fd[1]);
// 	execve(argv[idx], &argv[idx], envp);
// 	ft_error("Error: execve failed");
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int 	index;
// 	int 	fd[2];
// 	pid_t	pid;

// 	if (argc <= 4)
// 		ft_error("Error: insufficient arguments");

// 	if (strncmp(argv[1], "here_doc", 8) == 0)
// 	{
// 		index = 3;
// 		if (argc < 6)
// 			ft_error("Error: insufficient arguments");
// 		handle_here_doc(argv, fd);
// 	}
// 	else
// 	{
// 		index = 2;
// 		pid = fork();
// 		if (pid == -1)
// 			ft_error("Error: Failed to fork");
// 		if (pid == 0)
// 			ft_child_in(argv, envp, fd);
// 		close(fd[1]);
// 		if (waitpid(pid, NULL, 0) == -1)
// 			ft_error("Error: waitpid failed");
// 	}

// 	while (index < argc - 2)
// 	{
// 		pid = fork();
// 		if (pid == -1)
// 			ft_error("Error: Failed to fork");
// 		if (pid == 0)
// 			ft_child_out(index, argv, envp, fd);
// 		close(fd[0]);
// 		if (waitpid(pid, NULL, 0) == -1)
// 			ft_error("Error: waitpid failed");
// 		index++;
// 	}

// 	pid = fork();
// 	if (pid == -1)
// 		ft_error("Error: Failed to fork");
// 	if (pid == 0)
// 		ft_child_out(argc - 1, argv, envp, fd);
// 	close(fd[0]);
// 	if (waitpid(pid, NULL, 0) == -1)
// 		ft_error("Error: waitpid failed");

// 	return (0);
// }
int	main(int argc, char **argv, char **envp)
{
	int 	index;
	int 	fd[2];
	pid_t 	pid;
	char 	*line;

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
			line = get_next_line(STDIN_FILENO);
			while (line)
			{
				if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
					&& line[ft_strlen(argv[2])] == '\n')
				{
					free(line);
					break ;
				}
				write(fd[1], line, ft_strlen(line));
				free(line);
				line = get_next_line(STDIN_FILENO);
			}
			close(fd[1]);
			exit(0);
		}
		close(fd[1]);
		ft_dup2(fd[0], STDIN_FILENO);
		if (waitpid(pid, NULL, 0) == -1)
			ft_error("Error: waitpid failed\n");
		close(fd[0]);
	}
	else
	{
		index = 2;
		ft_process_input(argv, envp, fd);
	}
	while (index < argc - 2)
	{
		pid = fork();
		if (pid == -1)
			ft_error("Error: Failed to fork\n");
		if (pid == 0)
		{
			ft_dup2(fd[0], STDIN_FILENO);
			ft_dup2(fd[1], STDOUT_FILENO);
			ft_execute(argv[index], envp);
			close(fd[1]);
		}
		close(fd[0]);
		if (waitpid(pid, NULL, 0) == -1)
			ft_error("Error: waitpid failed\n");
		index++;
	}
	ft_process_output(argc - 1, argv, envp, fd);
	return (0);
}