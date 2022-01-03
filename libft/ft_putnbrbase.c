/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:08:20 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/01 13:20:27 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**a function that outputs any number based on the base
*/

int	ft_putnbrbase(long long nbr, char *ref, int base, int fd)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > base - 1)
		count += ft_putnbrbase(nbr / base, ref, base, fd);
	count += ft_putchar_fd(ref[nbr % base], fd);
	return (count);
}
