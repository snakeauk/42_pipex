/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:39:02 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/15 09:57:54 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_child_process(char *cmd, char **envp, int *fd)
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("Error: failed to duplicate file descriptor\n");
	close(fd[0]);
	ft_execute(cmd, envp);
}
