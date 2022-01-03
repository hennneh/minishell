/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:54:11 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 15:54:11 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The strchr() function returns a pointer to the first occurrence of the
**character c in the string s. return a pointer to the matched character or
**NULL if the character is not found. The terminating null byte is considered
**part of the string, so that if c is specified as aq\0aq, these functions return
**a pointer to the terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	unsigned int	pos;

	pos = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (&((char *)s)[pos]);
		pos ++;
	}
	if (s[pos] == c)
		return (&((char *)s)[pos]);
	return (0);
}
