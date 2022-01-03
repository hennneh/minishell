/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:46:58 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 20:46:58 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Function checks if variable c is a printable based on its numeric value
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (2048);
	}
	return (0);
}
