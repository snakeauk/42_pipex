/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:39:02 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/18 21:42:38 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_child(char *cmd, char **envp, int *fd)
{
	ft_dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	ft_execute(cmd, envp);
}