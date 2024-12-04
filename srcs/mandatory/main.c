/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:13 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/04 21:04:13 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		status;
	char	**cmd_list;

	status = EXIT_SUCCESS;
	if (argc != 5)
		ft_exit_message(EXIT_FAILURE, 22);
	if (is_here_doc(argv))
	{
		ft_dprintf(STDERR_FILENO, "Error: this is mandatory.\n");
		return (EXIT_FAILURE);
	}
	cmd_list = ft_split_cmd(argc, argv);
	if (!cmd_list)
		return (EXIT_FAILURE);
	status = pipex(argc, argv, envp, cmd_list);
	ft_free_array2((void **)cmd_list);
	return (status);
}
