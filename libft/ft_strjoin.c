/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:27:04 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 16:27:04 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates (with malloc(3)) and returns a new string, which is the result of
**the concatenation of ’s1’ and ’s2’. Returns The new string.
**NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		count1;
	int		count2;

	count1 = 0;
	count2 = 0;
	if (!s1 || !s2)
		return (0);
	join = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!join)
		return (0);
	while (s1[count1])
	{
		join[count1] = s1[count1];
		count1 ++;
	}
	while (s2[count2])
	{
		join[count1] = s2[count2];
		count1 ++;
		count2 ++;
	}
	return (join);
}
