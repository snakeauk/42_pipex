/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:04:33 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/04 21:04:38 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**ft_split_cmd(int argc, char **argv)
{
	char	**cmd_list;
	int		index;
	int		cmd_index;

	if (is_here_doc(argv))
		index = 3;
	else
		index = 2;
	cmd_list = (char **)malloc(sizeof(char *) * (argc - 1));
	if (!cmd_list)
		return (NULL);
	cmd_index = 0;
	while (index < argc - 1)
	{
		cmd_list[cmd_index] = ft_strdup(argv[index]);
		if (!cmd_list[cmd_index])
		{
			ft_free_array2((void **)cmd_list);
			return (NULL);
		}
		cmd_index++;
		index++;
	}
	cmd_list[cmd_index] = NULL;
	return (cmd_list);
}
