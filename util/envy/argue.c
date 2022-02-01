/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:33:47 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/01/20 04:14:31 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	finish editing the command arguments:
//	they first came seperated by quotation and otherwise spaces
//	by now variables have been replaced if necessary
//	so now let's stitch it back together into only seperation by spaces

char	**re_argue(t_seq *q, t_shell *s)
{
	int		i;
	int		l;
	char	**new;
	char	*tmp;

	i = 0;
	l = 0;
	while (q->cmd.cmd_args[i])
	{
		q->cmd.cmd_args[i] = inserter(q->cmd.cmd_args[i], s);
		if (q->cmd.cmd_args[i][ft_strlen(q->cmd.cmd_args[i]) - 1] == ' ')
			l++;
		i++;
	}
	new = ft_calloc(l + 2, sizeof(char *));
	i = 0;
	l = 0;
	while (q->cmd.cmd_args[i])
	{
		if (!new[l])
			new[l] = ft_calloc(1, 1);
		if (q->cmd.cmd_args[i][0] == '"')
			tmp = ft_strtrim(q->cmd.cmd_args[i], "\"");
		else if (q->cmd.cmd_args[i][0] == '\'')
			tmp = ft_strtrim(q->cmd.cmd_args[i], "\'");
		else
			tmp = ft_strdup(q->cmd.cmd_args[i]);
		new[l] = insert_string(new[l], tmp, ft_strlen(new[l]), 0);
		if (q->cmd.cmd_args[i][ft_strlen(q->cmd.cmd_args[i]) - 1] == ' ')
			l++;
		free(tmp);
		free(q->cmd.cmd_args[i]);
		i++;
	}
	free(q->cmd.cmd_args);
	return (new);
}

// void	hidecheat(t_seq	*q, char *del)
// {
// 	int	i;
// 	int	l;

// 	i = 0;
// 	while (q->cmd.cmd_args[i])
// 	{
// 		l = 0;
// 		while (q->cmd.cmd_args[i][l])
// 		{
// 			if (ft_strchr(del, q->cmd.cmd_args[i][l]))
// 				q->cmd.cmd_args[i][l] = "​";
// 			l++;
// 		}
// 		i++;
// 	}
// }

// int	main(int argc, char **argv, char **env)
// {
// 	t_shell	s;

// 	if (argc != 1 || argv[1])
// 		return(2);
// 	create_env(env, &s);
// 	g_return = 42;
// 	// disp_env(&s);
// 	t_seq	*q = ft_calloc(1, sizeof(t_seq));

// 	q->cmd.cmd_args = ft_calloc(4, sizeof(char *));
// 	q->cmd.cmd_args[0] = ft_strdup("$?");
// 	q->cmd.cmd_args[1] = ft_strdup("meh ");
// 	q->cmd.cmd_args[2] = ft_strdup("$0");
// 	q->cmd.cmd_args = re_argue(q, &s);
// 	// hidecheat(q, "\\");
// 	for (int i = 0;q->cmd.cmd_args[i]; i++)
// 		printf("new args	%s\n", q->cmd.cmd_args[i]);
	
// 	for (int i = 0; q->cmd.cmd_args[i]; i++)
// 		free(q->cmd.cmd_args[i]);
// 	free(q->cmd.cmd_args);
// 	free(q);
// 	return(0);
// }
