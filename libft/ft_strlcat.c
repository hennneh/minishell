/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:28:39 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 16:28:39 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Strlcat() functions concatenate strings. Strlcat() take the full
**size of the buffer and guarantee to NUL-terminate the result (as long as there
**is at least one byte free in dst). Note that a byte for the NUL should be
**included in size. Also note that strlcat() only operate on true ''C'' strings.
**This means that for strlcat() both src and dst must be NUL-terminated.
** return the total length of the string they tried to create, the initial 
**length of dst plus the length of src. 
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_pos;
	size_t	src_pos;

	if (!dst || !src)
		return (0);
	dst_pos = ft_strlen(dst);
	src_pos = ft_strlen(src);
	if (dst_pos < size - 1 && size > 0)
		ft_strlcpy(&dst[dst_pos], src, size - dst_pos);
	if (size < dst_pos)
		return (src_pos + size);
	return (dst_pos + src_pos);
}
