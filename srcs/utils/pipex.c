/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:47 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/05 00:03:02 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		pipex(int argc, char **argv, char **envp, char **cmd_list);
t_pipe	init_pipe(int argc, char **argv, char **envp, char **cmd_list);

t_pipe	init_pipe(int argc, char **argv, char **envp, char **cmd_list)
{
	t_pipe	data;

	data.env = get_env_path(envp);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	data.cmd_list = cmd_list;
	data.cmd_index = 0;
	if (is_here_doc(argv))
		data.cmd_size = argc - 4;
	else
		data.cmd_size = argc - 3;
	data.infile = 0;
	data.outfile = 0;
	return (data);
}

int	pipex(int argc, char **argv, char **envp, char **cmd_list)
{
	t_pipe	data;
	int		status;

	data = init_pipe(argc, argv, envp, cmd_list);
	if (!data.env)
		return (EXIT_FAILURE);
	status = ft_fork(&data);
	if (is_here_doc(argv))
		unlink(HEREDOC_TMP_FILE);
	if (status != EXIT_SUCCESS)
		return (status);
	return (status);
}
