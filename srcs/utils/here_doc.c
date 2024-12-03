#include "utils.h"

int	is_here_doc(char **argv);
int	read_line(int fd, char *limit);
int	here_doc(char *limit, t_pipe *data);

int	is_here_doc(char **argv)
{
	return (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8);
}

int	read_line(int fd, char *limit)
{
	char	*line;
	int		status;

	status = EXIT_SUCCESS;
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		if (get_next_line(STDIN_FILENO, &line) <= 0)
		{
			status = EXIT_FAILURE;
			break ;
		}
		if (ft_strlen(line) - 1 == ft_strlen(limit) && (!ft_strncmp(limit, line,
					ft_strlen(limit))))
			break ;
		if (ft_fputs(line, fd) < 0)
		{
			status = EXIT_FAILURE;
			break ;
		}
		free(line);
	}
	free(line);
	return (status);
}

int	here_doc(char *limit, t_pipe *data)
{
	int	fd;
	int	status;

	fd = ft_fopen(HEREDOC_TMP_FILE, "w");
	if (fd <= 0)
		return (EXIT_FAILURE);
	status = read_line(fd, limit);
	close(fd);
	if (status == EXIT_FAILURE)
	{
		unlink(HEREDOC_TMP_FILE);
		return (status);
	}
	data->infile = ft_fopen(HEREDOC_TMP_FILE, "r");
	if (data->infile <= 0)
	{
		unlink(HEREDOC_TMP_FILE);
		status = EXIT_FAILURE;
	}
	return (status);
}
