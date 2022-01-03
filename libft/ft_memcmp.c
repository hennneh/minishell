/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:38:11 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 12:38:11 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The memcmp() function compares the first n bytes (each interpreted as
**unsigned char) of the memory areas s1 and s2. returns an integer less than,
**equal to, or greater than zero if the first n bytes of s1 is found,
**respectively, to be less than, to match, or be greater than the first n bytes
**of s2.For a nonzero return value, the sign is determined by the sign of the
**difference between the first pair of bytes (interpreted as unsigned char)
**that differ in s1 and s2.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		value;
	size_t	pos;

	value = 0;
	pos = 0;
	while (n - pos > 0)
	{
		if (((unsigned char *)s1)[pos] != ((unsigned char *)s2)[pos])
			return (((unsigned char *)s1)[pos] - ((unsigned char *)s2)[pos]);
		pos ++;
	}
	return (value);
}
