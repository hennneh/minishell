/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:39:34 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 20:39:34 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function atoi transformes a string into an int
*/

int	ft_atoi(const char *nptr)
{
	int		result;
	int		sign;
	char	*temp;
	int		pos;

	temp = (char *)nptr;
	result = 0;
	pos = 0;
	sign = 1;
	while ((temp[pos] >= 9 && temp[pos] <= 13) || temp[pos] == 32)
		pos ++;
	if (temp[pos] == '-' || temp[pos] == '+')
	{
		if (temp[pos] == '-')
			sign = -1;
		pos ++;
	}
	while (temp[pos] >= 48 && temp[pos] <= 57)
	{
		result = (result * 10) + (temp[pos] - 48);
		pos ++;
	}
	return (result * sign);
}
