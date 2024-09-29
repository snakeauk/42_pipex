#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int     ret;
    char    **env;

    if (argc != 5)
        ft_exit(EXIT_FAILURE, "Error: Invalid number of arguments");
    env = ft_env(envp);
    if (!env)
        ft_exit(EXIT_FAILURE, "Error: PATH not found in environment variables");
    ret = ft_pipex(argc, argv, env);
    return (ret);
}