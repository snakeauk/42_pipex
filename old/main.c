/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:03:22 by mmoser            #+#    #+#             */
/*   Updated: 2024/10/30 01:55:26 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***cmd_split(size_t size, char **argv)
{
	char	***cmds;
	size_t	i;

	cmds = malloc((size + 1) * sizeof(char **));
	if (!cmds)
		ft_exit_message("cmd_split");
	i = 0;
	while (i < size)
	{
		cmds[i] = ft_split(argv[i], ' ');
		if (!cmds[i] || !cmds[i][0])
		{
			cmds[i + 1] = NULL;
			ft_free_array3((void ***)cmds);
			ft_exit_message("cmd_split");
		}
		i++;
	}
	cmds[size] = NULL;
	return (cmds);
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	info;
	int			num_cmds;
	int			stat_loc;
	pid_t		pid;

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
