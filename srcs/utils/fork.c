/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:51:30 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/30 02:51:33 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static void	ft_set_io(size_t index, size_t num_childs, t_pipe *data, int last)
{
	int	fd[2];

	if (index == 0)
		fd[0] = ft_fopen(data->infile, "r");
	else
		fd[0] = last;
	if (index == num_childs - 1)
	{
		if (data->here_doc)
			fd[1] = ft_fopen(data->outfile, "a");
		else
			fd[1] = ft_fopen(data->outfile, "w");
	}
	else
	{
		if (close(data->pipe[0]) < 0)
			ft_wait_free_exit(data->cmds, EXIT_FAILURE);
		fd[1] = data->pipe[1];
	}
	if (fd[0] < 0 || fd[1] < 0 || ft_iodup(fd[0], fd[1]) < 0)
		ft_wait_free_exit(data->cmds, EXIT_FAILURE);
}

static int	here_doc(t_pipe *data)
{
	char	*line;
	size_t	len;

	len = ft_strlen(data->limit);
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (ft_strncmp(line, data->limit, len) == 0 && line[len] == '\n')
		{
			free(line);
			ft_wait_free_exit(data->cmds, EXIT_SUCCESS);
		}
		write(data->pipe[1], line, ft_strlen(line));
		free(line);
	}
	return (EXIT_FAILURE);
}

static void	ft_execve(int index, t_pipe *data, char **env)
{
	if (data->here_doc)
		execve(data->cmds[index - 1][0], data->cmds[index - 1], env);
	else
		execve(data->cmds[index][0], data->cmds[index], env);
	ft_wait_free_exit(data->cmds, 127);
}

static void	close_fd(int index, int num_childs, t_pipe *data, int read_end)
{
	if (index != num_childs - 1)
	{
		if (close(data->pipe[1]) < 0)
			ft_wait_free_exit(data->cmds, EXIT_FAILURE);
	}
	if (index != 0)
	{
		if (close(read_end) < 0)
			ft_wait_free_exit(data->cmds, EXIT_FAILURE);
	}
}

pid_t	ft_fork(t_pipe *data, size_t num_childs, char **env)
{
	size_t	index;
	pid_t	pid;
	int		read_end;

	index = 0;
	read_end = -1;
	while (index < num_childs)
	{
		if (index < num_childs - 1 && pipe(data->pipe) < 0)
			ft_wait_free_exit(data->cmds, EXIT_FAILURE);
		pid = fork();
		if (pid < 0)
			ft_wait_free_exit(data->cmds, EXIT_FAILURE);
		else if (pid == 0)
		{
			if (index == 0 && data->here_doc)
				here_doc(data);
			ft_set_io(index, num_childs, data, read_end);
			ft_execve(index, data, env);
		}
		close_fd(index, num_childs, data, read_end);
		read_end = data->pipe[0];
		index++;
	}
	return (pid);
}
