/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:32:28 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 12:32:28 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The memchr() function scans the initial n bytes of the memory area pointed
**to by s for the first instance of c. Both c and the bytes of the memory area
**pointed to by s are interpreted as unsigned char. return a pointer to the
**matching byte or NULL if the character does not occur in the given memory area.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	pos;

	pos = 0;
	while (n > 0)
	{
		if (((char *)s)[pos] == c)
			return (&((char *)s)[pos]);
		n--;
		pos++;
	}
	return (0);
}
