/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:46:42 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 20:46:42 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Function checks if variable c is a ascii based on its numeric value
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (2048);
	}
	return (0);
}
