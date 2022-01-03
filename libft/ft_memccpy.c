/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:32:16 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 21:32:16 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The memccpy() function copies no more than n bytes from memory area src to
**memory area dest, stopping when the character c is found.returns a pointer
**to the next character in dest after c, or NULL if c was not found in the
**first n characters of src.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int	pos;

	pos = 0;
	while (n > 0)
	{
		((unsigned char *)dest)[pos] = ((unsigned char *)src)[pos];
		if (((unsigned char *)src)[pos] == c)
			return (&((unsigned char *)dest)[pos + 1]);
		n--;
		pos++;
	}
	return (0);
}
