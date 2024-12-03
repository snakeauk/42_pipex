#include "utils.h"

char	*get_env_path(char **envp)
{
	if (!envp)
		return (NULL);
	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (!*envp)
		return (NULL);
	return (*envp + 5);
}
