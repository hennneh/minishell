/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:06:48 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/24 18:06:48 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**tolower() converts the letter c to lower case, if possible.
**The value returned is that of the converted letter,
**or c if the conversion was not possible.
*/

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}
