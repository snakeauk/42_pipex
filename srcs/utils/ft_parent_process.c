/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:50:09 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/07 13:50:13 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(pid_t pid, int *fd)
{
	waitpid(pid, NULL, 0);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("");
	close(fd[1]);
}
