/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:44:59 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/21 20:44:59 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function ft_isalnum uses ft_isalpha and ft_isdigit to check if c is
**alphanumeric
*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
	{
		return (3056);
	}
	return (0);
}
