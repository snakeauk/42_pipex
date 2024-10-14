/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:38:26 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/14 11:45:52 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static int	**ft_create_pipe(int length)
{
	int	**ret;
	int	index;

	ret = (int **)malloc(sizeof(int *) * length);
	if (!ret)
	{
		ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < length)
	{
		ret[index] = (int *)malloc(sizeof(int) * 2);
		if (!ret[index])
		{
			ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
			ft_int_array_free(ret);
			exit(EXIT_FAILURE);
		}
		if (pipe(ret[index]) == -1)
		{
			ft_dprintf(STDERR_FILENO, "Error: Pipe creation failed\n");
			ft_int_array_free(ret);
			exit(EXIT_FAILURE);
		}
		index++;
	}
	return (ret);
}

void	ft_close_pipe(int **pipe, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		close(pipe[index][0]);
		close(pipe[index][1]);
		index++;
	}
}

void	ft_waitpid(pid_t *pids, int size, int *status)
{
	int	index;

	index = 0;
	while (index < size)
	{
		waitpid(pids[index], status, 0);
		index++;
	}
	free(pids);
}

int	ft_pipex(int argc, char **argv, char **env)
{
	int		status;
	int		**pipes;
	int		index;
	pid_t	*pids;

	pipes = ft_create_pipe(argc - 4);
	pids = (pid_t *)malloc(sizeof(pid_t) * (argc - 3));
	if (!pids)
		ft_exit(STDERR_FILENO, "Error: malloc failed");
	index = 0;
	while (index < argc - 3)
	{
		pids[index] = fork();
		if (pids[index] == -1)
			ft_exit(STDERR_FILENO, "Error: Fork failed");
		if (pids[index] == 0)
		{
			ft_stdio(argc, argv, pipes, index);
			ft_close_pipe(pipes, argc - 4);
			ft_execute(argv[2 + index], env);
			exit(EXIT_FAILURE);
		}
		index++;
	}
	ft_close_pipe(pipes, argc - 4);
	ft_waitpid(pids, argc - 3, &status);
	ft_int_array_free(pipes);
	return (status);
}
