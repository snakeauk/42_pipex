/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:40:55 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/18 21:32:29 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	if (argc != 5)
		ft_error("Error: Invalid number of arguments\n");
	if (pipe(fd) == -1)
		ft_error("Error: Failed to create pipe\n");
	ft_process_input(argv, envp, fd);
	ft_process_output(argc - 1, argv, envp, fd);
	return (0);
}
