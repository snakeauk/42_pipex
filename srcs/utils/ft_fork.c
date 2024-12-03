#include "utils.h"

int	ft_wait(t_pipe *data, int status)
{
	int pre;

	pre = status;
	if (data->cmd_limit > 0)
	{
		wait(&status);
		data->cmd_limit--;
		if (status != 0 || pre != 0)
			return (ft_wait(data, status));
		else
			return (ft_wait(data, status));
	}
	return (status);
	
}

int	ft_fork(t_pipe *data)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	if (pipe(pipefd) == -1)
		return (EXIT_FAILURE);
	while (data->cmd_index < data->cmd_limit)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			return (EXIT_FAILURE);
		}
		if (pid == 0)
		{
			ft_dup(data);
			ft_execve(data);
		}
		data->cmd_index++;
	}
	close(pipefd[0]);
	close(pipefd[1]);
	status = ft_wait(data, 0);
	return (status);
}
