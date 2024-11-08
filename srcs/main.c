#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		status;
	char	**cmd_list;

	if (argc < 5)
		ft_error("Error: Invalid number of arguments\n");
	if (is_here_doc(argv) && argc < 6)
		ft_exit_message(EXIT_FAILURE, "Error: Invalid number of arguments\n");
	cmd_list = ft_split_cmd(argc, argv);
	status = pipex(argc, argv, envp, cmd_list);
	ft_free_array2((void **)cmd_list);
	return (status);
}
