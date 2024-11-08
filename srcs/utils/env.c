#include "utils.h"

char	*get_env_path(char **envp)
{
	size_t	index;

	index = 0;
	while (envp && envp[index])
	{
		if (ft_strnstr(envp[index], "PATH=", 5) != NULL)
			return (envp[index]);
		index++;
	}
	ft_dprintf(EXIT_FAILURE, "Error: PATH not found\n");
	return (NULL);
}
