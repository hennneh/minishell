/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:39:56 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 12:39:56 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The memset() function fills the first n bytes of the memory area pointed
**to by s with the constant byte c. returns a pointer to the memory area s.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	int	pos;

	pos = 0;
	while (n > 0)
	{
		((unsigned char *)s)[pos] = c;
		n--;
		pos++;
	}
	return (s);
}
