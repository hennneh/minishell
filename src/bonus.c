/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:07:55 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:07:56 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv, char **env)
{
	if (argc > 1 || argv[1])
		return (printf("too many arguments\n") * 0 + 1);
	execve("/bin/bash", NULL, env);
	return (0);
}
