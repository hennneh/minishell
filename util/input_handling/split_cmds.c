/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:18:17 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/07 17:42:02 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
** count_cmds: counts the number of cmd seperators as to count the number of
** commands
*/

int	count_cmds(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (input[i])
	{
		if (input[i] == '<')
		{
			if (input[i + 1] == '<')
				i ++;
			count ++;
		}
		if (input[i] == '>')
		{
			if (input[i + 1] == '>')
				i ++;
			count ++;
		}
		if (input[i] == '|')
			count ++;
		i ++;
	}
	return (count);
}

/*
**
*/

t_cmd	*split_cmds(char *input)
{
	int	n_cmds;

	n_cmds = count_cmds(input);
	
}