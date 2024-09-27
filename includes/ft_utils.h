/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:35:51 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/27 23:35:23 by kinamura         ###   ########.fr       */
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
void	ft_process_input(char **argv, char **envp, int *fd);
void	ft_process_output(int index, char **argv, char **envp, int *fd);
void	ft_execute(char *command, char **envp);
int		ft_dup2(int fildes, int fildes2);
char	*ft_get_path(char *cmd, char **envp);
void	ft_parent_process(pid_t pid, int *fd);

#endif