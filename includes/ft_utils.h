/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:35:51 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/26 02:23:22 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>

#define READ_SIZE 1

void	ft_array_free(char **array);
void	ft_execute(char *command, char **envp);
void	ft_pipex(int argc, char **argv, char **envp);
int		ft_dup2(int fildes, int fildes2);
int 	ft_access(char *path);
char	*ft_get_path(char *cmd, char **envp);
void	ft_process(int argc, char **argv, char **envp, int *fd);
void	ft_process_child(char *cmd, char **envp, int *fd, int infile);
void	ft_process_parent(char *cmd, char **envp, int *fd, int outfile);

#endif