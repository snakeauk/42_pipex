#ifndef	UTILS_H
# define UTILS_H

#include "libft.h"
#include "ft_printf.h"
#include "ft_stdio.h"
#include "errno.h"

#define R 0
#define W 1

typedef struct	s_pipe
{
	int		argc;
	char	**argv;
	char	*env;
	char	**cmd_list;
	size_t	cmd_index;
	size_t	cmd_limit;
}				t_pipe;

void	ft_error_exit(int status, int err_message);
char	*get_env_path(char **envp);
char	**ft_split_cmd(int argc, char **argv);
int		is_here_doc(char **argv);
int	pipex(int argc, char **argv, char **envp, char **cmd_list);
t_pipe	init_pipe(int argc, char **argv, char **envp, char **cmd_list);

#endif