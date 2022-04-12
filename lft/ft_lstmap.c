/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/05/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;

	if (lst == NULL)
		return (NULL);
	dest = ft_lstnew(f(lst->content));
	if (dest == NULL)
		return (NULL);
	if (lst->next != NULL)
	{
		dest->next = ft_lstmap(lst->next, f, del);
		if (dest->next == NULL)
		{
			del(dest->content);
			free(dest);
			return (NULL);
		}
	}
	else
		dest->next = NULL;
	return (dest);
}
