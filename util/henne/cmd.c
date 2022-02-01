/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:47:08 by vheymans          #+#    #+#             */
/*   Updated: 2022/02/01 20:10:44 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_args(char **s)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i][0] != '<' || s[i][0] != '>')
			count ++;
		i ++;
	}
	return (count);
}

char	**arg_parsing(char **s)
{
	int		i;
	char	**cmd_arg;

	cmd_arg = ft_calloc(count_args(s) + 1, sizeof (char *));
	i = 0;
	while (i < count_args(s))
	{
		
	}
}

/*
**Make a new element of t_cmd type
*/

int	cmd_new(t_seq *s, char **path)// need to take out quotes and spaces 
{
	s->cmd_args = arg_parsing(s->split);
	if (s->cmd_args == 0)
		return (1);
	printf("cmd_args = %s\n", s->cmd_args[0]);
	if (s->wht_cmd > 0)
		s->path_cmd = NULL;
	else
	{
		s->path_cmd = ft_get_path(path, s->cmd_args);
		if (s->path_cmd == 0)
			return (1);
	}
	printf("path_cmd = %s\n", s->path_cmd);
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
