/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:40:38 by vheymans          #+#    #+#             */
/*   Updated: 2022/02/04 14:43:10 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_split(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	else if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else if (c == '<' || c == '>')
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
		if (s[i] == '\"' || s[i] == '\'')
		{
			i = quote_check(i, s[i], s);
			count ++;
		}
		else if (s[i] == '<' || s[i] == '>')
		{
			while (s[i + 1] == '<' || s[i + 1] == '>')
				i ++;
			count ++;
			i += is_whspace(&s[i + 1], 1);
		}
		else if (is_split(s[i]) && !is_split(s[i + 1]) && s[i + 1])
			count ++;
		i ++;
	}
	return (count);
}

int	cmd_split(char *s, t_seq *seq)
{
	int	pos1;
	int	pos2;
	int	n_args;

	seq->split = ft_calloc(count_split(s) + 1, sizeof(char *));
	if (!seq->split)
		return (1);
	pos1 = 0;
	n_args = 0;
	while (n_args < count_split(s))
	{
		while ((s[pos1] >= 9 && s[pos1] <= 13) || s[pos1] == 32)
			pos1++;
		if (s[pos1] == '\'' || s[pos1] == '\"')
			pos2 = quote_check(pos1, s[pos1], s);
		else
		{
			pos2 = pos1;
			if (s[pos2] == '<' || s[pos2] == '>')
				pos2 += is_whspace(&s[pos2 + 1], 1) + 1;
			while (!is_split(s[pos2]) && !(s[pos2] == '<' || s[pos2] == '>'))
				pos2 ++;
			if (s[pos2] == '<' || s[pos2] == '>' || s[pos2] == '\'' || s[pos2] == '\"')
				pos2 --;
		}
		seq->split[n_args] = ft_substr(s, pos1, pos2 + 1 - pos1);
		n_args ++;
		pos1 = pos2 + 1;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	argc ++;
	t_seq *seq;
	int i = 0;
	printf("\n\nSTART\n\n");
	seq = malloc(1 * sizeof(t_seq));
	cmd_split(argv[1], seq);
	while (seq->split[i])
	{
		printf("[%d] : [%s]\n", i, seq->split[i]);
		i ++;
	}
	return (0);
}*/