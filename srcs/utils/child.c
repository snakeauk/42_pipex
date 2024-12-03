#include "utils.h"

char	*get_command(char **paths, char *cmd);
int		ft_dup2(int read_fd, int out_fd);
void	child(t_pipe *data, int *pipefd);

char	*get_command(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*command;

	while (*paths)
	{
		cmd_path = ft_strjoin(*paths, "/");
		command = ft_strjoin(cmd_path, cmd);
		free(cmd_path);
		if ((access(command, F_OK) == 0) && (access(command, X_OK) == 0))
			return (command);
		else if ((access(command, F_OK) == 0) && (access(command, X_OK) < 0))
		{
			ft_dprintf(STDERR_FILENO, strerror(13));
			return (NULL);
		}
		free(command);
		paths++;
	}
	ft_dprintf(STDERR_FILENO, "Error: Command not find\n");
	return (NULL);
}

int	ft_dup2(int read_fd, int out_fd)
{
	if (dup2(read_fd, STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	if (dup2(out_fd, STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	child(t_pipe *data, int *pipefd)
{
	pid_t	pid;
	char	*cmd_path;
	char	**cmd_paths;

	pid = fork();
	if (pid)
	{
		if (!data->cmd)
			exit(127);
		if (data->cmd_index == 0)
			ft_dup2(data->infile, pipefd[1]);
		else if (data->cmd_index == data->cmd_size - 1)
			ft_dup2(pipefd[2 * data->cmd_index - 2], data->outfile);
		else
			ft_dup2(pipefd[2 * data->cmd_index - 2], pipefd[2 * data->cmd_index
					+ 1]);
		close_pipes(pipefd, data);
		cmd_paths = ft_split(data->env, ':');
		cmd_path = get_command(cmd_paths, data->cmd[0]);
		if (!cmd_path || data->infile < 0 || data->outfile < 0)
			exit(128);
		execve(cmd_path, data->cmd, data->envp);
		exit(128);
	}
}
