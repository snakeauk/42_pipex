#include "utils.h"

t_pipe	*init_pipe(int argc, char **argv, char **envp, char **commands)
{
	t_pipe	*pipe;

	pipe = (t_pipe *)malloc(sizeof(t_pipe));
	if (!pipe)
	{
		perror("Error: ");
		return (NULL);
	}
	pipe->env = get_env_path(envp);
	if (!pipe->env)
	{
		free(pipe);
		return (NULL);
	}
	pipe->argc = argc;
	pipe->argv = argv;
	pipe->infile = -1;
	pipe->outfile = -1;
	pipe->cmd_list = commands;
	pipe->cmd_index = 0;
	pipe->cmd_limit = argc - 3;
	pipe->status = EXIT_SUCCESS;
	return (pipe);
}

int	pipex(int argc, char **argv, char **envp, char **commands)
{
	t_pipe	*pipe;
	int		status;

	pipe = init_pipe(argc, argv, envp, commands);
	if (!pipe)
		return (EXIT_FAILURE);
	status = pipe->status;
	free(pipe);
	return (status);
}