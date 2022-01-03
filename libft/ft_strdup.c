/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:25:49 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 16:25:49 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The strdup() function returns a pointer to a new string which is a duplicate
**of the string s. Memory for the new string is obtained with malloc(3), and
**can be freed with free(3).returns a pointer to the duplicated string, or
**NULL if insufficient memory was available.
*/

char	*ft_strdup(const char *s)
{
	char	*new;
	int		pos;

	pos = ft_strlen(s);
	new = malloc(pos + 1);
	while (pos >= 0)
	{
		new[pos] = s[pos];
		pos--;
	}
	return (new);
}
