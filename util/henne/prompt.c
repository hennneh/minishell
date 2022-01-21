/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 07:53:13 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/21 09:22:49 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char *get_user(t_shell *shell)
{

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
