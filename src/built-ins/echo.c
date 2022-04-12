/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:08:35 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:08:37 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ms_echo(char **array, pid_t pid)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!array[1] && !pid)
	{
		printf("\n");
		return ;
	}
	if (ft_strlen(array[1]) == 2 && !ft_strncmp(array[1], "-n", 2))
	{
		flag++;
		i++;
	}
	while (array[i] && !pid)
	{
		printf("%s", array[i]);
		i++;
		if (array[i])
			printf (" ");
	}
	if (!flag && !pid)
		printf("\n");
	g_errnum = 0;
}
