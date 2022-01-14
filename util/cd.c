/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:18:48 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/14 14:08:03 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	cd_rest(t_shell *shell, char *dir)
{
	ft_getcwd(shell);
	if (!shell->pwd || !dir)
		return (1);
	new = ft_strjoin(shell->pwd, "/");
	temp = ft_strjoin(new, dir);
	free(new);
	ret = chdir(temp);
	if (ret)
	{
		free(temp);
		return (1);
	}
	free(temp);
	ft_getcwd(shell);
	return (0);
}

/*
 * changing to parent dir and updating shell->pwd variable to new dir
 */

int	cd_parent(t_shell *shell)
{
	int	i;

	ft_getcwd(shell);
	i = ft_strlen(shell->pwd);
	while (i > 0)
	{
		if (shell->pwd[i] == '/')
			break ;
		i--;
	}
	shell->pwd[i] = '\0';
	return (chdir(shell->pwd));
}

int	cd(t_shell *shell, char *dir)
{
	if (dir)
	{
		if (ft_strlen(dir) == 1 && dir[0] == '.')
			return (0);
		else if (ft_strlen(dir) == 2 && dir[0] == '.' && dir[1] == '.')
			return (cd_parent(shell));
		else
			return (cd_rest(shell, dir));
	}
}
