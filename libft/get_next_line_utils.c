/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:32:52 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/21 14:11:40 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

/*
** Function ft_bzero fills pointer s with nulls till it has reached size n
*/

char	*ft_isnewchar(char *buff)
{
	unsigned int	pos;

	pos = 0;
	while (buff[pos])
	{
		if (buff[pos] == '\n')
			return (&((char *)buff)[pos + 1]);
		pos ++;
	}
	if (buff[pos] == '\n')
		return (&((char *)buff)[pos + 1]);
	return (0);
}
