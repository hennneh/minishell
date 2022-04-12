/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arg_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:10:52 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:10:53 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/**
 * is_split checks if it is a split
 * @param c [char] char to be checked
 * @return [int] 1 if quote, 2 if white, 3 if rad, 0 if not
*/
int	is_split(char c)
{
	if (c == D_Q || c == S_Q)
		return (1);
	else if (ft_white(c))
		return (2);
	else if (c == '<' || c == '>')
		return (3);
	return (0);
}

int	red_check(int i, char *s)
{
	while (is_split(s[i]) == 3)
	{
		i ++;
	}
	while (is_split(s[i]) == 2)
	{
		i ++;
	}
	return (i);
}

int	wrd_check(int i, char *s)
{
	while (s[i] && !is_split(s[i]))
	{
		i ++;
	}
	return (i);
}

/**
 * counts the number of splits needed
 * @param s [char *] s = sequance being split
 * @return [int] number of splits
*/
int	count_split(char *s)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		i += is_whspace(&s[i], 1);
		while (s[i] && !ft_white(s[i]))
		{
			if (is_split(s[i]) == 3)
				i = red_check(i, s);
			else if (is_split(s[i]) == 1)
				i = pipe_quote(i + 1, s[i], s) + 1;
			else if (!is_split(s[i]))
				i = wrd_check(i, s);
			if (is_split(s[i]) == 3)
				break ;
		}
		if (!s[i] || (ft_white(s[i]) && !s[i + is_whspace(&s[i], 1)]))
			break ;
		count ++;
	}
	return (count);
}

/**
 * @param s		[char *] sequance being split
 * @param seq	[t_seq *] sequance struct
 * @param pos1	[int] always '0' (because I have too many lines)
 * @param i		[int] always '0' (because I have too many lines)
 * @return [int] 0 if successful, 1 if malloc failed
*/
int	arg_split(char *s, t_seq *seq, int pos1, int i)
{
	int	pos2;

	seq->nbr_arg = count_split(s);
	seq->split = ft_calloc(seq->nbr_arg + 1, sizeof(char *));
	if (!seq->split)
		return (1);
	while (i < seq->nbr_arg)
	{
		pos1 += is_whspace(&s[pos1], 1);
		pos2 = pos1;
		while (s[pos2] && !ft_white(s[pos2]))
		{
			if (is_split(s[pos2]) == 3)
				pos2 = red_check(pos2, s);
			else if (is_split(s[pos2]) == 1)
				pos2 = pipe_quote(pos2 + 1, s[pos2], s) + 1;
			else if (!is_split(s[pos2]))
				pos2 = wrd_check(pos2, s);
			if (is_split(s[pos2]) == 3)
				break ;
		}
		seq->split[i ++] = ft_substr(s, pos1, pos2 - pos1);
		pos1 = pos2;
	}
	return (0);
}
