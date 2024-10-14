/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:40:18 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/14 11:40:19 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define READ_SIZE 1

int		ft_access(char *filepath);
int		ft_pipex(int argc, char **argv, char **envp);
char	**ft_env(char **envp);
void	ft_exit(int status, char *message);
void	ft_execute(char *command, char **env);
char	*ft_get_path(char *cmd, char **env);
void	ft_int_array_free(int **array);
void	ft_char_array_free(char **array);
int		ft_here_doc(int argc, char **argv, char **env);
void	ft_stdio(int argc, char **argv, int **pipes, int index);

#endif