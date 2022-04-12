/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:09:04 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:09:10 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief display the current working directory
 * @param pid [pid_t]	child-or-not pid
*/
void	pwd(pid_t pid)
{
	char	path[MAX_PATH];
	char	*check;

	check = NULL;
	check = getcwd(path, MAX_PATH);
	if (!check)
		return ;
	if (!pid)
		printf("%s\n", path);
	g_errnum = 0;
}
