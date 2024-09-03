/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:43:40 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 00:43:48 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "ft_utils.h"

// ft_child_process.c
void	ft_child_process(char *cmd, char **envp);

// ft_here_doc.c
void	ft_here_doc(char *limiter, int argc);

// main.c
int 	main(int argc, char **argv, char **envp);

#endif