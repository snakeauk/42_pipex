#include "ft_utils.h"

static  void    ft_stdin(int infile, int **pipes, int index)
{
    if (index == 0)
    {
        dup2(infile, STDIN_FILENO);
        close(infile);
    }
    else
        dup2(pipes[index - 1][0], STDIN_FILENO);
}

static  void    ft_stdout(int argc, int outfile, int **pipes, int index)
{
    if (index == argc - 4)
    {
        dup2(outfile, STDOUT_FILENO);
        close(outfile);
    }
    else
        dup2(pipes[index][1], STDOUT_FILENO);
}

int ft_infile(int argc, char **argv, int *file, int *index)
{
    int ret;

    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
        if (argc < 6)
        {
            ft_dprintf(STDERR_FILENO, "Error: Invalid number of arguments\n");
            return (EXIT_FAILURE);
        }
        *index = 3; // "here_doc"とリミッターの後から開始
        ret = 1;
    }
    else
    {
        *file = ft_fopen(argv[1], "r");
        if (*file < 0)
        {
            ft_dprintf(STDERR_FILENO, "Error: Failed to open input file\n");
            return (EXIT_FAILURE);
        }
        *index = 2; // 入力ファイルの後から開始
        ret = 0;
    }
    return (ret);
}

void ft_here_doc(char *limiter, int argc, int **pipe)
{
    pid_t pid;
    char *line;

    if (argc < 6)
        ft_error("Error: insufficient arguments\n");
    pid = fork();
    if (pid == -1)
        ft_error("Error: failed to fork\n");
    if (pid == 0)
    {
        close(pipe[0][0]); // 読み取り側をクローズ
        while ((line = get_next_line(0)) != NULL)
        {
            if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && line[ft_strlen(limiter)] == '\n')
            {
                free(line);
                break;
            }
            if (write(pipe[0][1], line, ft_strlen(line)) == -1)
            {
                free(line);
                close(pipe[0][1]);
                ft_error("Error: failed to write to pipe\n");
            }
            free(line);
        }
        close(pipe[0][1]);
        exit(0);
    }
    else
    {
        close(pipe[0][1]); // 親プロセスで書き込み側をクローズ
        waitpid(pid, NULL, 0); // 子プロセスを待機
    }
}
static int ft_file_open(int argc, char **argv, int *file, int **pipe)
{
    int ret;

    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
        if (argc < 6)
        {
            ft_dprintf(STDERR_FILENO, "Error: Invalid number of arguments\n");
            exit(EXIT_FAILURE);
        }
        ret = 3;
        ft_here_doc(argv[2], argc, pipe);
        file[0] = pipe[0][0];
    }
    else
    {
        ret = 2;
        file[0] = ft_fopen(argv[1], "r");
        if (file[0] < 0)
        {
            ft_dprintf(STDERR_FILENO, "Error: Failed to open input file\n");
            exit(EXIT_FAILURE);
        }
    }
    file[1] = ft_fopen(argv[argc - 1], "w");
    if (file[1] < 0)
    {
        ft_dprintf(STDERR_FILENO, "Error: Failed to open output file\n");
        exit(EXIT_FAILURE);
    }
    return (ret);
}
static  void ft_int_array_free(int **array, int size)
{
    int index;

    index = 0;
    while (index < size)
    {
        free(array[index]);
        index++;
    }
    free(array);
}

static  int **ft_create_pipe(int length)
{
    int **ret;
    int index;

    ret = (int **)malloc(sizeof(int *) * (length));
    if (!ret)
        exit(EXIT_FAILURE);
    index = 0;
    while (index < length)
    {
        ret[index] = (int *)malloc(sizeof(int) * 2);
        if (!ret[index])
        {
            ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
            ft_int_array_free(ret, index);
        }
        if (pipe(ret[index]) == -1)
        {
            ft_dprintf(STDERR_FILENO, "Error: Pipe creation failed\n");
            ft_int_array_free(ret, index);
        }
        index++;
    }
    return (ret);
}

void    ft_close_pipe(int **pipe, int length)
{
    int index;

    index = 0;
    while (index < length)
    {
        close(pipe[index][0]);
        close(pipe[index][1]);
        index++;
    }
}

static  void    ft_parent_process(int argc, int **pipes, int *status)
{
    int index;

    ft_close_pipe(pipes, argc - 4);
    index = 0;
    while (index < argc - 3)
    {
        wait(status);
        index++;
    }
    ft_int_array_free(pipes, argc - 4);
}

static  void    ft_iofile(int argc, int **pipes, int index, int *file)
{
    ft_stdin(file[0], pipes, index);
    ft_stdout(argc, file[1], pipes, index);
}

int ft_pipex(int argc, char **argv, char **envp)
{
    int     file[2];
    int     **pipes;
    int     ret;
    pid_t   pid;
    int     status;
    int     index;
    int     cmd_count;
    int     last_cmd_index;

    pipes = ft_create_pipe(argc - 4);
    ret = ft_file_open(argc, argv, file, pipes);
    if (ret == EXIT_FAILURE)
        exit(EXIT_FAILURE);
    cmd_count = argc - ret - 1;
    last_cmd_index = cmd_count - 1;
    index = 0;
    while (index < cmd_count)
    {
        pid = fork();
        if (pid == -1)
            ft_error("Error: Fork failed");
        if (pid == 0)
        {
            ft_iofile(file[0], file[1], pipes, index, last_cmd_index);
            ft_close_pipe(pipes, argc - 4);
            ft_execute(argv[ret + index], envp);
            exit(EXIT_FAILURE);
        }
        index++;
    }
    ft_parent_process(argc, pipes, &status);
    return (WEXITSTATUS(status));
}