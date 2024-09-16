/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:50:09 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/15 09:55:17 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(pid_t pid, int *fd)
{
	if (waitpid(pid, NULL, 0) == -1)
		ft_error("Error: waitpid failed\n");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("Error: dup2 failed for stdin\n");
}
