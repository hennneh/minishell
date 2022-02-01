/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:17:06 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/19 16:34:21 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**whitespace trims the white spaces off of a string
*/

/*
** is_whspace iterates through a line till it does not find a whitespace
*/

int	is_whspace(char *s, int dir)
{
	int	i;

	i = 0;
	if (dir < 0)
		i = ft_strlen(s);
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
	{
		i += dir;
	}
	return (i);
}

/*
**trim_whitespace trims whitesspaces
**if dir == 1 from the front, if -1 then from the back, if 2 then from both
*/

char	*trim_whitespace(char *s, int dir)
{
	char	*trim;
	int		pos1;
	int		pos2;

	if (!s)
		return (NULL);
	if (dir > 0)
	{
		pos1 = is_whspace(s, 1);
		if (dir == 2)
			dir = -1;
	}
	else
		pos1 = 0;
	if (dir == -1)
		pos2 = is_whspace(s, -1) + 1;
	else
		pos2 = ft_strlen(s);
	if (pos2 <= pos1)
		return (""); //Return empty string if string only whitespace?
	trim = ft_substr(s, pos1, pos2 - pos1);
	free(s);
	return (trim);
}
// return with a space at the end of arg if arg
