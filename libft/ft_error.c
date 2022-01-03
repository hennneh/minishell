/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:23:07 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/20 16:40:55 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Takes a string and prints it to the std output, then exits with (1)
*/

int	ft_error(char *str, int fd)
{
	ft_putstr_fd("ERROR\n", fd);
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
	exit(EXIT_FAILURE);
	return (0);
}
