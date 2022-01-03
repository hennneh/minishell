/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:47:34 by vheymans          #+#    #+#             */
/*   Updated: 2021/05/22 12:47:34 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Outputs the character ’c’ to the given file descriptor.
*/

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) > 0)
		return (1);
	return (0);
}
