/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:18 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/06 16:53:33 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*get_command(char **paths, char *cmd);
int		ft_dup2(t_pipe *data, int *pipefd);
void	child(t_pipe *data, int *pipefd);

char	*get_command(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*command;
	int		index;

	index = 0;
	while (paths[index])
	{
		cmd_path = ft_strjoin(paths[index], "/");
		command = ft_strjoin(cmd_path, cmd);
		free(cmd_path);
		if ((access(command, F_OK) == 0) && (access(command, X_OK) == 0))
			return (command);
		else if ((access(command, F_OK) == 0) && (access(command, X_OK) < 0))
		{
			perror(cmd);
			free(command);
			return (NULL);
		}
		free(command);
		index++;
	}
	ft_dprintf(STDERR_FILENO, "%s: command not found\n", cmd);
	return (NULL);
}

int	ft_dup2(t_pipe *data, int *pipefd)
{
	int	ret_r;
	int	ret_w;

	if (data->cmd_index == 0)
	{
		ret_r = dup2(data->infile, STDIN_FILENO);
		ret_w = dup2(pipefd[1], STDOUT_FILENO);
	}
	else if (data->cmd_index == data->cmd_size - 1)
	{
		ret_r = dup2(pipefd[2 * data->cmd_index - 2], STDIN_FILENO);
		ret_w = dup2(data->outfile, STDOUT_FILENO);
	}
	else
	{
		ret_r = dup2(pipefd[2 * data->cmd_index - 2], STDIN_FILENO);
		ret_w = dup2(pipefd[2 * data->cmd_index + 1], STDOUT_FILENO);
	}
	if (ret_r < 0 || ret_w < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	child(t_pipe *data, int *pipefd)
{
	pid_t	pid;
	char	*cmd_path;

	pid = fork();
	if (pid < 0)
		perror("Error: fork");
	if (pid == 0)
	{
		if (!data->cmd)
			exit(128);
		if (open_iofile(data) != EXIT_SUCCESS)
			exit(EXIT_FAILURE);
		if (ft_dup2(data, pipefd) != EXIT_SUCCESS)
			exit(EXIT_FAILURE);
		close_pipes(pipefd, data);
		cmd_path = get_command(data->cmd_paths, data->cmd[0]);
		if (!cmd_path)
			exit(128);
		execve(cmd_path, data->cmd, data->envp);
		ft_free_array2((void **)data->cmd);
		free(cmd_path);
		exit(128);
	}
}
