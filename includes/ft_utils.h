/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:35:51 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 00:36:25 by kinamura         ###   ########.fr       */
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

void	ft_error(void);
void	ft_execute(char *cmd, char **envp);
char	*ft_get_path(char *cmd, char **envp);
int		ft_line_size(char **line);
int		ft_open_file(char *filename, int opt);

#endif