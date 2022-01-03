/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:46:33 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/03 14:50:06 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell(void)
{
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 1 && strncmp(argv[0], "./minishell", strlen(argv[0])))
		ft_error("fuck", 2);
	if (shell())
		ft_error("fuck2", 2);
	return (0);
}
