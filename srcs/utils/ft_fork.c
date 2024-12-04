/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:29 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/05 02:20:36 by ubuntu           ###   ########.fr       */
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
	pipefd = (int *)malloc(sizeof(int) * (data->cmd_size - 1) * 2);
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
	int	status;

	index = 0;
	status = EXIT_SUCCESS;
	while (index < 2 * (data->cmd_size - 1))
	{
		if (close(pipefd[index]) < 0)
		{
			perror("Error");
			status = EXIT_FAILURE;
		}
		index++;
	}
	return (status);
}

int	ft_wait(t_pipe *data)
{
	int	index;
	int	s;
	int	status;

	index = 0;
	status = EXIT_SUCCESS;
	s = EXIT_SUCCESS;
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
		ft_free_array2((void **)data->cmd);
		data->cmd_index++;
	}
	status = close_pipes(pipefd, data);
	status = ft_wait(data);
	free(pipefd);
	ft_free_array2((void **)data->cmd_paths);
	return (status);
}
