#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		status;
	char	**cmd_list;

	if (argc < 5)
		ft_error_exit(EXIT_FAILURE, 22);
	if (is_here_doc(argv) && argc < 6)
		ft_exit_exit(EXIT_FAILURE, 22);
	cmd_list = ft_split_cmd(argc, argv);
	status = pipex(argc, argv, envp, cmd_list);
	ft_free_array2((void **)cmd_list);
	return (status);
}
