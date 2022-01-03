/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:16:33 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/25 17:16:33 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The memmove() function copies n bytes from memory area src to memory area dest.
**The memory areas may overlap: copying takes place as though the bytes in src
**are first copied into a temporary array that does not overlap src or dest,
**and the bytes are then copied from the temporary array to dest.
**Returns a pointer to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	pos;
	char	*temp_dest;
	char	*temp_src;

	pos = 0;
	if (!dest || !src)
		return (0);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	if (temp_src < temp_dest)
	{
		while (n > 0)
		{
			n --;
			temp_dest[n] = temp_src[n];
		}
		return (dest);
	}
	while (pos < n)
	{
		temp_dest[pos] = temp_src[pos];
		pos ++;
	}
	return (dest);
}
