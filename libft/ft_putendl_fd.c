/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:46:36 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 12:46:36 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Outputs the string ’s’ to the given file descriptor, followed by a newline.
*/

int	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
	{
		if (write(fd, &s[len], 1) > 0)
			len ++;
		else
			return (0);
	}
	if (write(fd, "\n", 1) > 0)
		len ++;
	else
		return (0);
	return (len);
}
