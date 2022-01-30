/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:40:38 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/28 18:23:25 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
int	is_split(char c)
{
	if(c == '\'' || c == '\"')
		return (1);
	else if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	count_split(char *s)
{
	int	i;
	int	count;

	count = 1;
	i = is_whspace(s, 1);
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\'')
		{
			i = quote_check(i + 1, s[i], s);
			count ++;
		}
		else if (is_split(s[i]) && is_split(s[i + 1]) && s[i + 1])
			count ++;
		else if (s[i] == '<' || s[i] == '>')
		{
			count ++;
			return (count);
		}
		i ++;
	}
	return (count);
}

int	cmd_split(char *s, t_cmd *cmd)
{
	int	pos1;
	int	pos2;
	int	n_args;

	cmd->cmd_args = ft_calloc(count_split(s) + 1, sizeof(char *));
	if (!cmd->cmd_args)
		return (1);
	pos1 = 0;
	n_args = 0;
	printf("[%d]\n", count_split(s));
	while (n_args < count_split(s))
	{
		while ((s[pos1] >= 9 && s[pos1] <= 13) || s[pos1] == 32)
			pos1++;
		if (s[pos1] == '\'' || s[pos1] == '\"')
			pos2 = quote_check(pos1 + 1, s[pos1], s);
		else
		{
			pos2 = pos1;
			while (!((s[pos1] >= 9 && s[pos1] <= 13) || s[pos1] == 32) && !(s[pos1] == '\'' || s[pos1] == '\"'))
				pos2 ++;
		}
		cmd->cmd_args[n_args] = ft_substr(s, pos1, pos2 + 1 - pos1);
		printf("[%d] : [%s]\n", n_args, cmd->cmd_args[n_args]);
		n_args ++;
		pos1 = pos2;
	}
	printf("done split\n");
	return (0);
}

int	main(int argc, char **argv)
{
	argc ++;
	t_cmd *cmd;
	int i = 0;
	printf("\n\nSTART\n\n");
	cmd = malloc(1 * sizeof(t_cmd));
	cmd_split(argv[1], cmd);
	while (cmd->cmd_args[i])
	{
		printf("[%d] : %s\n", i, cmd->cmd_args[i]);
		i ++;
	}
	return (0);
}