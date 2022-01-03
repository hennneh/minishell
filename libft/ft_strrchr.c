/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:24:34 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 16:24:34 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The strrchr() function returns a pointer to the last occurrence of the
**character c in the string s. return a pointer to the matched character or
**NULL if the character is not found. The terminating null byte is considered
**part of the string, so that if c is specified as aq\0aq, these functions return
**a pointer to the terminator.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = 0;
	p = 0;
	while (((char *)s)[i])
	{
		if (((char *)s)[i] == c)
			p = &((char *)s)[i];
		i++;
	}
	if (((char *)s)[i] == c)
		p = &((char *)s)[i];
	return (p);
}
