/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:54:06 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/30 02:54:09 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipe	info;
	int			num_cmds;
	int			stat_loc;
	pid_t		pid;

	if (argc != 5)
		return (EXIT_FAILURE);
	num_cmds = argc - 3;
	info.here_doc = (argc > 1 && ft_strncmp(argv[1], "here_doc", 9) == 0);
	if (info.here_doc)
	{
		info.limit = argv[2];
		num_cmds--;
	}
	if (num_cmds < 2)
		exit(EXIT_FAILURE);
	info.infile = argv[1];
	info.outfile = argv[argc - 1];
	info.cmds = cmd_split(num_cmds, &argv[2 + info.here_doc]);
	set_cmd_path(info.cmds, env);
	pid = ft_fork(&info, num_cmds + info.here_doc, env);
	waitpid(pid, &stat_loc, 0);
	ft_wait_free_exit(info.cmds, WEXITSTATUS(stat_loc));
}
