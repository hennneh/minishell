/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:29:02 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/24 13:29:02 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**strlcpy() functions copy strings. strlcpy() take the full
**size of the buffer and guarantee to NUL-terminate the result (as long as size
**is larger than 0). Note that a byte for the NUL should be
**included in size. Also note that strlcpy() only operate on true ''C'' strings.
**This means that for strlcpy() both src must be NUL-terminated.
** return the total length of the string they tried to create, that
**means the length of src.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	pos;

	pos = 0;
	if (!dst || !src)
		return (0);
	while (pos < size - 1 && src[pos] && size > 0)
	{
		dst[pos] = ((unsigned char *)src)[pos];
		pos++;
	}
	if (size > 0)
		dst[pos] = '\0';
	return (ft_strlen(src));
}
