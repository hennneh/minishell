/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:41:22 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/26 12:36:37 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Adds the element ’new_ele’ at the beginning of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new_ele)
{
	new_ele -> next = *lst;
	*lst = new_ele;
}
