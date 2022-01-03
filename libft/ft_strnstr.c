/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:38:23 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/24 13:38:23 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**strnstr function locates the first occurrence of the null-terminated
**string needle in the string haystack, where not more than len characters are
**searched. Characters that appear after a `\0' character are not searched.
**If needle is an empty string, haystack is returned; if needle occurs nowhere
**in haystack, NULL is returned; otherwise a pointer to the first character
**of the first occurrence of needle is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos;
	size_t	needlelen;

	pos = 0;
	if (haystack[pos] == needle[pos])
		pos = 0;
	if (ft_memcmp(needle, "", 1) == 0)
		return ((char *)haystack);
	needlelen = ft_strlen((char *)needle);
	while (len - pos >= needlelen && haystack[pos])
	{
		if (ft_memcmp((char *)&haystack[pos], needle, needlelen) == 0)
			return ((char *)&haystack[pos]);
		pos ++;
	}
	return (0);
}
