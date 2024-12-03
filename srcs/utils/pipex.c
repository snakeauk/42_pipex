#include "utils.h"

int	pipex(int argc, char **argv, char **envp, char **cmd_list);
t_pipe	init_pipe(int argc, char **argv, char **envp, char **cmd_list);

t_pipe	init_pipe(int argc, char **argv, char **envp, char **cmd_list)
{
	t_pipe	data;

	data.env = get_env_path(envp);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	data.cmd_list = cmd_list;
	data.cmd_index = 0;
	if (is_here_doc(argv))
		data.cmd_size = argc - 4;
	else
		data.cmd_size = argc - 3;
	return (data);
}

int	pipex(int argc, char **argv, char **envp, char **cmd_list)
{
	t_pipe	data;
	int		status[2];

	data = init_pipe(argc, argv, envp, cmd_list);
	if (!data.env)
		return (EXIT_FAILURE);
	status[0] = file_open(argc, argv, &data);
	status[1] = ft_fork(&data);
	if (is_here_doc(argv))
		unlink(HEREDOC_TMP_FILE);
	if (status[1] != EXIT_SUCCESS)
		return (status[1]);
	return (status[0]);
}
