/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:05:49 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:05:51 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	dest = (char *)ft_calloc(sizeof(*s), (len + 1));
	i = 0;
	while (len > i)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
