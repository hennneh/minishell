/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:29:56 by vheymans          #+#    #+#             */
/*   Updated: 2021/08/28 14:29:18 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates (with malloc(3)) and returns a new element. The variable ’content’
**is initialized with the value of the parameter ’content’. The variable ’next’
**is initialized to NULL.
**Returns the new element.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!tmp)
		return (0);
	tmp -> content = content;
	return (tmp);
}
