/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:33:32 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/24 13:33:32 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Applies the function ’f’ to each character of the string ’s’ to create
**a new string (with malloc(3)) resulting from successive applications of ’f’
**Returns The string created from the successive applications of ’f’.
**Returns NULL if the allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		pos;

	pos = 0;
	if (!s || !(*f))
		return (0);
	new = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new)
		return (0);
	while (s[pos])
	{
		new[pos] = (*f)(pos, s[pos]);
		pos ++;
	}
	return (new);
}
