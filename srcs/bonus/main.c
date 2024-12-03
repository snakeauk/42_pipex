#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		status;
	char	**cmd_list;

	status = EXIT_SUCCESS;
	if (argc < 5)
		ft_exit_message(EXIT_FAILURE, 22);
	if (is_here_doc(argv) && argc < 6)
		ft_exit_message(EXIT_FAILURE, 22);
	cmd_list = ft_split_cmd(argc, argv);
	if (!cmd_list)
		return (EXIT_FAILURE);
	status = pipex(argc, argv, envp, cmd_list);
	ft_free_array2((void **)cmd_list);
	return (status);
}
