#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	ret;

	if (argc != 5)
	{
		ft_dprintf(STDERR_FILENO, "Error: Invalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	ret = ft_pipex(argc, argv, envp);
	return (ret);
}