/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:07:20 by vheymans          #+#    #+#             */
/*   Updated: 2022/02/05 16:32:39 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
**Handles all the spliting of the input 
*/

/*
**check for quotes (could have $SOMETHING)
**check for pipes
**check for cmds (echo $sfds)
**check for args (include spaces after arg)
**check for FDs
** heredoc and what not
**output char **
*/

/*
**if_quotes
**0 = outside of quotes; 1 == ""; 2 = '';
*/

int	quote_check(int pos, char c, char *in)
{
	while (in[pos] == c)
	{
		pos ++;
		while (in[pos] && in[pos] != c)
		{
			pos++;
		}
		if (in[pos + 1] == '\"' || in[pos + 1] == '\'')
		{
			c = in[pos + 1];
			pos ++;
		}
		else
			break ;
	}
	return (pos);
}

int		count_pipe(char *in)// what if it ends with a pipe == missing bash cmd; triple |||?
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (in[i])
	{
		if (in[i] == 34 || in[i] == '\'')
			i = quote_check(i + 1, in[i], in);
		if (in[i] == PIPE)
		{
			if (in[i + 1] != PIPE)
				count ++;
			if (in[i + 1] && in[i + 1] == PIPE)
				return (-1);
		}
		i ++;
	}
	return (count);
}

int		pipe_split(t_shell *shell, char *in)
{
	int	n_pipes;
	int	pos1;
	int	pos2;

	shell->n_cmds = count_pipe(in);
	if (shell->n_cmds < 1)
		return (1);
	shell->seq = malloc(shell->n_cmds * sizeof(t_seq *));
	n_pipes = 0;
	pos1 = 0;
	pos2 = 0;
	while (n_pipes < shell->n_cmds)
	{
		while (in[pos2] && in[pos2] != PIPE)
		{
			if (in[pos2] == 34 || in[pos2] == '\'')
				pos2 = quote_check(pos2, in[pos2], in);
			pos2 ++;
		}
		if (!in[pos2] || in[pos2 + 1] != PIPE)
		{
			shell->seq[n_pipes] = malloc(sizeof(t_seq));
			shell->seq[n_pipes]->seq = ft_substr(in, pos1, pos2 - pos1);
			n_pipes ++;
			pos1 = ++ pos2;
		}
		while (in[pos2] == PIPE && in[pos2])
			pos2 ++;
	}
	return (0);
}
