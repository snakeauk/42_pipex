/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:29 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/04 21:10:22 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	*create_pipes(t_pipe *data);
int	close_pipes(int *pipefd, t_pipe *data);
int	ft_wait(t_pipe *data);
int	ft_fork(t_pipe *data);

int	*create_pipes(t_pipe *data)
{
	int	index;
	int	*pipefd;

	index = 0;
	pipefd = (int *)malloc(sizeof(int) * data->cmd_size - 1);
	if (!pipefd)
		return (NULL);
	while (index < data->cmd_size - 1)
	{
		if (pipe(pipefd + 2 * index) < 0)
		{
			perror("Error");
			free(pipefd);
			return (NULL);
		}
		index++;
	}
	return (pipefd);
}

int	close_pipes(int *pipefd, t_pipe *data)
{
	int	index;

	index = 0;
	while (index < data->cmd_size - 1)
	{
		if (close(pipefd[index]) < 0)
		{
			perror("Error");
			return (EXIT_FAILURE);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}

int	ft_wait(t_pipe *data)
{
	int	index;
	int	s;
	int	status;

	index = 0;
	status = EXIT_SUCCESS;
	while (index < data->cmd_size)
	{
		wait(&s);
		if (status == EXIT_SUCCESS)
			status = s;
		index++;
	}
	return (status);
}

int	ft_fork(t_pipe *data)
{
	int	status;
	int	*pipefd;

	pipefd = create_pipes(data);
	if (!pipefd)
		return (EXIT_FAILURE);
	data->cmd_index = 0;
	data->cmd_paths = ft_split(data->env, ':');
	if (!data->cmd_paths)
		return (EXIT_FAILURE);
	while (data->cmd_index < data->cmd_size)
	{
		data->cmd = ft_split(data->cmd_list[data->cmd_index], ' ');
		child(data, pipefd);
		free((void **)data->cmd);
		data->cmd_index++;
	}
	ft_free_array2((void **)data->cmd_paths);
	status = close_pipes(pipefd, data);
	if (status != EXIT_SUCCESS)
		return (status);
	status = ft_wait(data);
	return (status);
}
