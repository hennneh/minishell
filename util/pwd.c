/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:44:04 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/18 17:06:45 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_getcwd(t_shell *shell);

/*
 * updating current working directory and printing it
 */

void	pwd(t_shell *shell)
{
	ft_getcwd(shell);
	printf("%s\n", shell->pwd);
}

/*
 * allocating memory for the path and setting shell->pwd to new path with getcwd
 */

void	ft_getcwd(t_shell *shell)
{
	char	*dir;
	char	*ret;
	int		i;

	i = 1;
	dir = malloc(sizeof(char) * i);
	dir = NULL;
	ret = NULL;
	while (!ret)
	{
		free(dir);
		i++;
		dir = malloc(sizeof(char) * i);
		ret = getcwd(dir, i);
	}
	if (shell->pwd)
		free(shell->pwd);
	shell->pwd = dir;
}

// /*
//  * main for testing purposes
//  */

// int	main(void)
// {
// 	t_shell	shell;
// 	shell.pwd = malloc(1);
// 	shell.pwd[0] = 'p';
// 	pwd(&shell);
// 	int i = 0;
// 	while (shell.pwd[i])
// 	{
// 		write(1, &shell.pwd[i], 1);
// 		i++;
// 	}
// 	return (0);
// }
