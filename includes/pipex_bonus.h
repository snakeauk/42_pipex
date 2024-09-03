/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:50:06 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 22:10:44 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "ft_utils.h"

// ft_child_process.c
void	ft_child_process(char *cmd, char **envp);

// ft_here_doc.c
void	ft_here_doc(char *limiter, int argc);

// pipex_bonus.c
int 	main(int argc, char **argv, char **envp);

#endif