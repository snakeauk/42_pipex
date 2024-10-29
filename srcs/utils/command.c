#include "ft_utils.h"
#include <unistd.h>

char	***cmd_split(size_t size, char **argv);
char	*get_env_path(char **envp);
char	**get_bin_paths(char **env);
int		create_command(char **cmd, char **bin_paths);
void	set_cmd_path(char ***cmds, char **envp);

char	***cmd_split(size_t size, char **argv)
{
	char	***cmds;
	size_t	index;

	cmds = (char ***)malloc((size + 1) * sizeof(char **));
	if (!cmds)
		ft_exit_message("Error: cmds malloc");
	index = 0;
	while (index < size)
	{
		cmds[index] = ft_split(argv[index], ' ');
		if (!cmds[index] || !cmds[index][0])
		{
			cmds[index + 1] = NULL;
			ft_free_array3((void ***)cmds);
			ft_exit_message("Error: cmd split");
		}
		index++;
	}
	cmds[size] = NULL;
	return (cmds);
}

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
	ft_dprintf(STDERR_FILENO, "Error: PATH not found\n");
	return (NULL);
}

char	**get_bin_paths(char **envp)
{
	char	**bin_paths;
	char	*env_path;
	char	*temp;
	size_t	i;

	env_path = get_env_path(envp);
	if (!env_path)
		return (NULL);
	bin_paths = ft_split(env_path + 5, ':');
	if (!bin_paths)
		return (NULL);
	i = 0;
	while (bin_paths[i])
	{
		temp = ft_strjoin(bin_paths[i], "/");
		if (!temp)
		{
			ft_free_array2((void **) bin_paths);
			return (NULL);
		}
		free(bin_paths[i]);
		bin_paths[i] = temp;
		i++;
	}
	return (bin_paths);
}

int	create_command(char **cmd, char **bin_paths)
{
	char	*command;
	size_t	index;

	index = 0;
	while (bin_paths[index])
	{
		command = ft_strjoin(bin_paths[index], *cmd);
		if (!command)
		{
			perror("ERROR occurred when creating command path");
			return (ERROR);
		}
		if (access(command, X_OK) == 0)
		{
			free(*cmd);
			*cmd = command;
			return (0);
		}
		free(command);
		index++;
	}
	return (0);
}

void	set_cmd_path(char ***cmds, char **envp)
{
	size_t	index;
	char	**bin_paths;

	bin_paths = get_bin_paths(envp);
	if (!bin_paths)
	{
		ft_free_array3((void ***) cmds);
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (cmds[index])
	{
		if (access(cmds[index][0], X_OK) != 0)
		{
			if (create_command(cmds[index], bin_paths) == ERROR)
			{
				ft_free_array3((void ***)cmds);
				ft_free_array2((void **)bin_paths);
				exit (EXIT_FAILURE);
			}
		}
		index++;
	}
	ft_free_array2((void **)bin_paths);
}
