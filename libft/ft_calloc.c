/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:43:05 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 20:43:05 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function ft_calloc uses melloc and ft_bzero to make a pointer p and fill it
** with \0
*/

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;

	p = malloc(nelem * elsize);
	if (!p)
		return (0);
	ft_bzero(p, nelem * elsize);
	return (p);
}
