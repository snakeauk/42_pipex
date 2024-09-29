#include "ft_utils.h"
#include "ft_utils.h"

void ft_process_child(int argc, char **argv, char **env, int *fd)
{
    int outfile;

    outfile = ft_fopen(argv[argc - 1], "a");
    if (dup2(fd[0], STDIN_FILENO) == -1)
        ft_exit(STDERR_FILENO, "dup2 failed for STDIN_FILENO");
    if (dup2(outfile, STDOUT_FILENO) == -1)
        ft_exit(STDERR_FILENO, "dup2 failed for STDOUT_FILENO");
    close(fd[0]);
    close(outfile);
    ft_execute(argv[3], env);
    exit(EXIT_FAILURE);
}

int ft_here_doc(int argc, char **argv, char **env)
{
    pid_t	pid1;
	pid_t	pid2;
    int		status;
    char	*line;
    int		fd[2];

    if (pipe(fd) == -1)
        ft_exit(STDERR_FILENO, "Pipe creation failed");
    pid1 = fork();
    if (pid1 == -1)
        ft_exit(STDERR_FILENO, "Fork failed");
    if (pid1 == 0)
    {
        close(fd[0]);
		line = get_next_line(STDIN_FILENO);
        while (line)
        {
            if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
            {
                free(line);
                break;
            }
            write(fd[1], line, ft_strlen(line));
            free(line);
			line = get_next_line(STDIN_FILENO);
        }
        close(fd[1]);
        exit(EXIT_SUCCESS);
    }
    close(fd[1]);
    waitpid(pid1, &status, 0);
    pid2 = fork();
    if (pid2 == -1)
        ft_exit(STDERR_FILENO, "Fork failed");
    if (pid2 == 0)
        ft_process_child(argc, argv, env, fd);
    close(fd[0]);
    waitpid(pid2, &status, 0);
    return status;
}