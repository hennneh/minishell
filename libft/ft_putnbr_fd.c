/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:49:12 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 12:49:12 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Outputs the integer ’n’ to the given file descriptor.
*/

int	ft_putnbr_fd(int num, int fd)
{
	int	count;

	count = 0;
	if (num == -2147483648)
	{
		if (write(fd, "-2147483648", 11) > 0)
			return (11);
	}
	else
	{
		if (num < 0)
		{
			if (write(fd, "-", 1) > 0)
				count ++;
			num = num * -1;
		}
		if (num > 9)
			count += ft_putnbr_fd(num / 10, fd);
		num = (num % 10) + 48;
		if (write(fd, &num, 1) > 0)
			count ++;
	}
	return (count);
}
