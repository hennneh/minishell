/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:41:31 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 20:41:31 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function ft_bzero fills pointer s with nulls till it has reached size n
*/

void	ft_bzero(void *s, size_t n)
{
	int	pos;

	pos = 0;
	while (n > 0)
	{
		((unsigned char *)s)[pos] = '\0';
		n --;
		pos ++;
	}
}
