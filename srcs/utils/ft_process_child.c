/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:16:11 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/20 00:16:16 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process_child(char *cmd, char **envp, int *fd, int infile)
{
	ft_dup2(infile, STDIN_FILENO);
	close(infile);
	ft_dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	ft_execute(cmd, envp);
}
