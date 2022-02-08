/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmv_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:52:09 by vheymans          #+#    #+#             */
/*   Updated: 2022/02/07 17:06:10 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	arg_len(char *s)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			c = s[i];
			i ++;
			while (s[i] && s[i] != c)
			{
				i ++;
				count ++;
			}
		}
		else
			count ++;
		i ++;
	}
	return (count);
}

char	*rmv_quotes(char *s)
{
	int		i;
	int		x;
	char	*new;
	char	c;

	new = ft_calloc(arg_len(s) + 1, sizeof(char));
	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			c = s[i];
			i ++;
			while (s[i] && s[i] != c)
				new[x ++] = s[i ++];
		}
		else
			new[x ++] = s[i];
		i ++;
	}
	return (new);
}
