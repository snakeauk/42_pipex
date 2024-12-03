#include "utils.h"

int	pipex(int argc, char **argv, char **envp, char **cmd_list);
t_pipe	init_pipe(int argc, char **argv, char **envp, char **cmd_list);

t_pipe	init_pipe(int argc, char **argv, char **envp, char **cmd_list)
{
	t_pipe	*data;

	data = (t_pipe *)malloc(sizeof(t_pipe));
	if (!data)
	{
		perror("Error");
		return (NULL);
	}
	data->env = get_env_path(envp);
	if (!data->env)
	{
		free(data);
		return (NULL);
	}
	data->argc = argc;
	data->argv = argv;
	data->cmd_list = cmd_list;
	data->cmd_index = 0;
	if (is_here_doc(argv))
		data->cmd_limit = argc - 4;
	else
		data->cmd_limit = argc - 3;
	return (data);
}

int	pipex(int argc, char **argv, char **envp, char **cmd_list)
{
	t_pipe	data;
	int		status;

	data = init_pipe(argc, argv, envp, cmd_list);
	if (!data)
		return (EXIT_FAILURE);
	status = ft_fork(data);
	free(data);
	return (status);
}