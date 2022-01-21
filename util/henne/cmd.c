/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:47:08 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/21 09:21:57 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
**
*/

void	free_cmd(t_cmd *elem, int nelem)
{
	int		i;

	i = 0;
	while (i <= nelem)
	{
		if (elem[i].cmd_args)
			free_2dstr(elem[i].cmd_args);
		if (elem[i].path_cmd)
			free(elem[i].path_cmd);
		i ++;
	}
}

/*
**Make a new element of t_cmd type
*/

int	cmd_new(t_cmd *new, t_seq *s, char **path)
{
	new->cmd_args = ft_split(ft_substr(s->seq, 0, ft_strlen(s->seq) - ft_strlen(find_limitor(s->seq))), ' ');
	if (new->cmd_args == 0)
		return (1);
	printf("cmd_args = %s\n", new->cmd_args[0]);
	if (s->wht_cmd > 0)
		new->path_cmd = NULL;
	else
	{
		new->path_cmd = ft_get_path(path, new->cmd_args);
		if (new->path_cmd == 0)
			return (1);
	}
	printf("path_cmd = %s\n", new->path_cmd);
	return (0);
}

// t_cmd	*cmd_line(int n_cmds, char **argv, char **path)
// {
// 	t_cmd	*cmd_line;
// 	int		x;

// 	x = 0;
// 	cmd_line = (t_cmd *)malloc(n_cmds * sizeof(t_cmd));
// 	if (!cmd_line)
// 		return (NULL);
// 	while (x < n_cmds)
// 	{
// 		if (cmd_new(&cmd_line[x], argv[x + 2], path))
// 		{
// 			free_cmd(cmd_line, x);
// 			free(cmd_line);
// 			free_2dstr(path);
// 			return (NULL);
// 		}
// 		x ++;
// 	}
// 	return (cmd_line);
// }
