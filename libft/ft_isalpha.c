/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:46:35 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 20:46:35 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Function checks if variable c is a letter based on its numeric value
*/

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1024);
	}
	else if (c >= 97 && c <= 122)
	{
		return (1024);
	}
	return (0);
}
