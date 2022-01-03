/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:38:37 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/26 12:35:42 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Adds the element ’new_ele’ at the end of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new_ele)
{
	t_list	*last;

	if (!new_ele)
		return ;
	if (*lst == NULL)
		*lst = new_ele;
	else
	{
		last = *lst;
		last = ft_lstlast(last);
		last -> next = new_ele;
	}
}
