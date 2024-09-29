#include "ft_utils.h"

void	ft_execute(char *command, char **envp)
{
    char	**cmd;
    char	*path;

    cmd = ft_split(command, ' ');
    if (!cmd || !cmd[0])
    {
        ft_array_free(cmd);
        perror("Error: command parsing failed");
        exit(EXIT_FAILURE);
    }
    path = ft_get_path(cmd[0], envp);
    if (!path)
    {
        fprintf(stderr, "%s: command not found\n", cmd[0]);
        ft_array_free(cmd);
        exit(EXIT_FAILURE);
    }
    if (execve(path, cmd, envp) == -1)
    {
        perror("Error");
        ft_array_free(cmd);
        free(path);
        exit(EXIT_FAILURE);
    }
}
