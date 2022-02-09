/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:08:26 by vheymans          #+#    #+#             */
/*   Updated: 2022/02/04 18:33:34 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_split(char c)
{
	if (!c)
		return (0);
	if (c == '\'' || c == '\"')
		return (1);
	else if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	red_check(int i, char *s)
{
	i ++;
	while (is_split(s[i]))
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			while (s[i] == '\'' || s[i] == '\"')
				i = quote_check(i, s[i], s) + 1;
			break ;
		}
		i ++;
	}
	while (s[i] && !is_split(s[i]))
		i ++;
	return (i);
}

int	wrd_check(int i, char *s)
{
	while (s[i] && !is_split(s[i]))
				i ++;
	return (i);
}

int	cnt_cmd(char *s, int count)
{
	int	i;

	i = is_whspace(s, 1);
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			count ++;
			i = quote_check(i, s[i], s);
		}
		else if (s[i] == '<' || s[i] == '>')
		{
			count ++;
			i = red_check(i, s) + 1;
		}
		else if (!is_split(s[i]))
		{
			count ++;
			while (s[i] && !is_split(s[i]))
				i ++;
		}
		i ++;
	}
	return (count);
}

int	ms_cmd_split(char *s, t_seq *seq, int pos1, int n_args)
{
	int	pos2;

	seq->split = ft_calloc(cnt_cmd(s, 0) + 1, sizeof(char *));
	if (!seq->split)
		return (1);
	while (n_args < cnt_cmd(s, 0))
	{
		while ((s[pos1] >= 9 && s[pos1] <= 13) || s[pos1] == 32)
			pos1++;
		if (s[pos1] == '>' || s[pos1] == '<')
			pos2 = red_check(pos1, s) + 1;
		if (s[pos1] == '\'' || s[pos1] == '\"')
			pos2 = quote_check(pos1, s[pos1], s) + 1;
		if (s[pos1] && !is_split(s[pos1]))
			pos2 = wrd_check(pos1, s);
		if (!s[pos2])
			seq->split[n_args] = ft_substr(s, pos1, pos2 + 1 - pos1);
		else
			seq->split[n_args] = ft_substr(s, pos1, pos2 - pos1);
		n_args ++;
		pos1 = pos2 + 1;
	}
	return (0);
}
