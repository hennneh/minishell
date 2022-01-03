/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:31:07 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 13:31:07 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates (with malloc(3)) and returns a substring from the string ’s’.
**The substring begins at index ’start’ and is of maximum size ’len’.
**Returns the substring. NULL if the allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	new;

	new = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	sub = ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (0);
	while (new < len)
	{
		sub[new] = s[start];
		start ++;
		new ++;
	}
	return (sub);
}
