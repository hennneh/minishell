/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:47:43 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 20:47:43 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function ft_numsize returns the size of int n
*/

static int	ft_numsize(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size ++;
	while (n != 0)
	{
		n = n / 10;
		size ++;
	}
	return (size);
}

/*
** Function ft_itoa returns a string with the int n
*/

char	*ft_itoa(int n)
{
	int			size;
	char		*p;
	int long	num;

	num = n;
	size = ft_numsize(n);
	p = ft_calloc(size + 1, 1);
	if (!p)
		return (0);
	if (num < 0)
	{
		p[0] = '-';
		num = num * -1;
	}
	while (num >= 10)
	{
		size --;
		p[size] = (num % 10) + 48;
		num = num / 10;
	}
	p[size - 1] = (num % 10) + 48;
	return (p);
}
