/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:11:33 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:11:35 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Handles all the spliting between pipes of the input 
*/

#include "../../../inc/minishell.h"

/**
 * returns the pos in string where the quote's end
 * @param pos [int] pos of the start of the quote
 * @param c [char] if double or single quotes
 * @param in [char *] string being checked
 * @return [int] pos of end of quote
*/
int	pipe_quote(int pos, char c, char *in)
{
	while (in[pos] && in[pos] != c)
		pos++;
	return (pos);
}

/**
 * count_pipe returns the number of pipes and therefor splits needed
 * @param in [char *] string input
 * @return [int] number of splits needed
*/
int	count_pipe(char *in)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (in && in[i])
	{
		if (in[i] == D_Q || in[i] == S_Q)
			i = pipe_quote(i + 1, in[i], in);
		if (in[i] == PIPE)
		{
			if (in[i + 1] && in[i + 1] != PIPE)
				count ++;
			else
			{
				ms_error(258, ft_strjoin
					("syntax error near unexpected token `|'", ""), "\n", 1);
				return (-1);
			}
		}
		i ++;
	}
	return (count);
}

/**
 * pipe_splits splits `in` by pipes
 * @param shell [t_shell *] shell struct
 * @param in [char *] input string
 * @param pos1 [int] always '0' (because I have too many lines)
 * @param pos2 [int] always '0' (because I have too many lines)
 * @return 1 if error in pipe count, 0 if succes
*/
int	pipe_split(t_shell *shell, char *in, int pos1, int pos2)
{
	int	n_pipes;

	shell->n_cmds = count_pipe(in);
	if (shell->n_cmds < 1)
		return (1);
	shell->seq = ft_calloc(shell->n_cmds + 1, sizeof(t_seq *));
	n_pipes = 0;
	while (n_pipes < shell->n_cmds)
	{
		while (in[pos2] && in[pos2] != PIPE)
		{
			if (in[pos2] == D_Q || in[pos2] == S_Q)
				pos2 = pipe_quote(pos2 + 1, in[pos2], in);
			pos2 ++;
		}
		if (!in[pos2] || (in[pos2 + 1] && in[pos2 + 1] != PIPE))
		{
			shell->seq[n_pipes] = ft_calloc(sizeof(t_seq), 1);
			shell->seq[n_pipes ++]->seq = ft_substr(in, pos1, pos2 - pos1);
			pos1 = ++ pos2;
		}
		while (pos2 < (int)ft_strlen(in) && in[pos2] && in[pos2] == PIPE)
			pos2 ++;
	}
	return (0);
}
