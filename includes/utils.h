/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:05:27 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/05 00:00:20 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"
# include "ft_stdio.h"
# include "libft.h"
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

# define HEREDOC_TMP_FILE "/tmp/.heredoc_tmp"

typedef struct s_pipe
{
	int		argc;
	char	**argv;
	char	**envp;
	char	*env;
	char	**cmd_list;
	char	**cmd_paths;
	char	**cmd;
	int		cmd_index;
	int		cmd_size;
	int		infile;
	int		outfile;
}			t_pipe;

t_pipe		init_pipe(int argc, char **argv, char **envp, char **cmd_list);
char		*get_env_path(char **envp);
char		**ft_split_cmd(int argc, char **argv);
int			pipex(int argc, char **argv, char **envp, char **cmd_list);

// file.c
int			open_infile(t_pipe *data);
int			open_outfile(t_pipe *data);

// child.c
char		*get_command(char **paths, char *cmd);
int			ft_dup2(t_pipe *data, int *pipefd);
void		child(t_pipe *data, int *pipefd);

// fork.c
int			*create_pipes(t_pipe *data);
int			close_pipes(int *pipefd, t_pipe *data);
int			ft_wait(t_pipe *data);
int			ft_fork(t_pipe *data);

// here_doc.c
int			is_here_doc(char **argv);
int			read_line(int fd, char *limit);
int			here_doc(char *limit, t_pipe *data);

#endif