/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:43:19 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/24 13:43:19 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
**specified in ’set’ removed from the beginning and the end of the string.
**Returns the trimmed string. NULL if the allocation fails.
*/

static int	ft_str_pos(char const *s1, char const *set, int direction)
{
	int	pos;
	int	posset;

	posset = 0;
	pos = 0;
	if (direction < 0)
		pos = ft_strlen(s1) - 1;
	while (set[posset] && s1[pos] && pos >= 0)
	{
		if (s1[pos] == set[posset])
		{
			pos = pos + direction;
			posset = 0;
		}
		else
			posset ++;
	}
	return (pos);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		pos1;
	int		pos2;

	if (!s1 || !set)
		return (0);
	pos1 = ft_str_pos(s1, set, 1);
	pos2 = ft_str_pos(s1, set, -1) + 1;
	if (pos2 <= pos1)
		pos2 = ft_strlen(s1);
	new = ft_substr(s1, pos1, pos2 - pos1);
	return (new);
}
