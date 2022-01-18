/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_limitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:17:49 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/12 14:20:49 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
**checks a string for the next limitor (<, <<, >, >>) and returns that char.
**returns NULL if nothing is found
*/

char	*find_limitor(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '<')
		{
			if (s[i + 1] == '<')
				return (&s[i + 1]);
			return (&s[i]);
		}
		if (s[i] == '>')
		{
			if (s[i + 1] == '>')
				return (&s[i + 1]);
			return (&s[i]);
		}
		i ++;
	}
	return (&s[i]);
}
