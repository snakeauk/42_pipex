#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		ret;
	char	**env;

	if (argc < 5)
		ft_exit(EXIT_FAILURE, "Error: Invalid number of arguments");
    env = ft_env(envp);
    if (!env)
        ft_exit(EXIT_FAILURE, "Error: PATH not found in environment variables");
    if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
	{
		if (argc < 6)
			ft_exit(EXIT_FAILURE, "Error: Invalid number of arguments");
		ret = ft_here_doc(argc, argv, env);
	}
	else
		ret = ft_pipex(argc, argv, env);
	return (ret);
}
