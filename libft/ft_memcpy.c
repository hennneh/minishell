/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:33:36 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 12:33:36 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The memcpy() function copies n bytes from memory area src to memory area
**dest. The memory areas must not overlap. Returns a pointer to dest.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	pos;

	pos = 0;
	while (n > 0)
	{
		((unsigned char *)dest)[pos] = ((unsigned char *)src)[pos];
		n--;
		pos++;
	}
	return (dest);
}
