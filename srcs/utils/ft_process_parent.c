/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:50:09 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/20 00:15:35 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_process_parent(char *cmd, char **envp, int *fd, int outfile)
{
	ft_dup2(outfile, STDOUT_FILENO);
	close(outfile);
	ft_dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	ft_execute(cmd, envp);
	close(fd[0]);
}
