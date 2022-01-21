/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 07:53:13 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/21 13:55:23 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

}

char *ft_join_shell(char *user, char *path)
{

}

char *prompt(t_shell *shell)
{
	char	*user;
	char	*prompt;
	char	*path;

	user = get_user(shell);
	if (!user)
		return (0);
	ft_getcwd(shell);
	path = get_last_dir(shell);
	prompt = ft_join_shell(user, path);
	return (prompt);
}
