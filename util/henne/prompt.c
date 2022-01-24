/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 07:53:13 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/24 09:34:45 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_user(char *s)
{
	if (s[0] == 'U' && s[1] == 'S' && s[2] == 'E' && s[3] == 'R' && s[4] == '=')
		return (1);
	return (0);
}

char *get_user(t_shell *shell)
{
	int		i;
	int		j;
	int		k;
	char	*user;

	i = 0;
	j = 5;
	k = 0;
	while (shell->env[i])
	{
		if (find_user(shell->env[i]))
		{
			user = malloc(sizeof(char) * ft_strlen(shell->env[i] - 4));
			while (shell->env[i][j])
			{
				user[k] = shell->env[i][j];
				k++;
				j++;
			}
			return (user);
		}
		i++;
	}
	return (NULL);
}

char *get_last_dir(t_shell *shell)
{
	char	*dir;
	int		len;
	char	*last;
	int		i;
	int		j;

	dir = strrchr(shell->pwd, '/');
	len = ft_strlen(dir);
	last = malloc(sizeof(char) * len);
	i = 1;
	j = 0;
	while (dir[i])
	{
		last[j] = dir[i];
		j++;
		i++;
	}
	return (last);
}

/*
 * function that prints the prompt
 */

void prompt(t_shell *shell)
{
	char	*user;
	char	*path;

	user = get_user(shell);
	if (!user)
		return ;
//	ft_getcwd(shell);
	path = get_last_dir(shell);
	printf("%s: %s$", user, path);
}
