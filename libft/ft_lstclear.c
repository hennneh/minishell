/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:58:20 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/27 15:31:22 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Deletes and frees the given element and every successor of that element,
**using the function ’del’ and free(3).
**Finally, the pointer to the list must be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	else
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			next = tmp -> next;
			(*del)(tmp -> content);
			free(tmp);
			tmp = next;
		}
		*lst = NULL;
	}
}
