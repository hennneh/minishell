/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:08:20 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:08:21 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	updateold(t_shell *shell)
{
	t_list	*old;
	t_list	*new;
	char	*tmp;

	old = finder(shell->env, "OLDPWD");
	new = finder(shell->env, "PWD");
	if (old)
	{
		free(((t_cont *)old->content)->value);
		((t_cont *)old->content)->value = \
			ft_strdup(((t_cont *)new->content)->value);
	}
	else
	{
		tmp = ft_strjoin("OLDPWD=", ((t_cont *)new->content)->value);
		ft_lstadd_back(&shell->env, ft_lstnew(envar(tmp)));
		free(tmp);
	}
}

void	updatenew(t_shell *shell, char *new_pwd)
{
	t_list	*new;

	new = finder(shell->env, "PWD");
	free(((t_cont *)new->content)->value);
	((t_cont *)new->content)->value = ft_strdup(new_pwd);
}

void	cd(char **array, t_shell *shell, pid_t pid)
{
	char	*oldpwd;
	char	*newpwd;

	(void) pid;
	oldpwd = NULL;
	newpwd = NULL;
	oldpwd = getcwd(oldpwd, MAX_DIR);
	if (oldpwd == NULL)
		return ;
	if (chdir(array[1]) == 0)
	{
		updateold(shell);
		newpwd = getcwd(newpwd, MAX_DIR);
		updatenew(shell, newpwd);
		g_errnum = 0;
	}
	else
		if (pid != 0)
			ms_error(1, ft_strjoin("cd: no such file or directory: ", \
				array[1]), "\n", pid);
	if (oldpwd)
		free(oldpwd);
	if (newpwd)
		free(newpwd);
}
