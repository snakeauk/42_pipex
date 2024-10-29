/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:35:51 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/30 02:00:03 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# define ERROR -1

typedef struct s_pipe
{
	char	***cmds;
	int		pipe[2];
	int		here_doc;
	char	*limit;
	char	*infile;
	char	*outfile;
}			t_pipe;

// dup.c
int			ft_iodup(int infile, int outfile);

// utils.c
void	ft_free_array3(void ***array);
void	ft_free_array2(void **array);
void	ft_wait_free_exit(char ***cmds, int exit_status);
void	ft_exit_message(char *message);

// ft_fork.c
pid_t		ft_fork(t_pipe *data, size_t num_childs, char **env);

// command.c
char		***cmd_split(size_t size, char **argv);
void		set_cmd_path(char ***cmds, char **env);

#endif