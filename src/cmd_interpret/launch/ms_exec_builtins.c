/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:10:27 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:10:28 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ms_exec_extension(t_shell *s, t_seq *q, pid_t pid);

/**
 * @brief execute the builtins and commands respectively in child and parent
 * @param s [t_shell*] shell
 * @param q [t_seq*]	sequence
 * @param pid [pid_t]	child-or-not pid
*/
void	ms_exec_builtins(t_shell *s, t_seq *q, pid_t pid)
{
	char	**p_env;

	p_env = env_copy(s->env);
	if (q->wht_cmd == 1 && !pid)
	{
		execve(q->path_cmd, q->cmd_args, p_env);
	}
	else
	{
		ms_exec_extension(s, q, pid);
	}
	del_list(p_env);
}

void	ms_exec_extension(t_shell *s, t_seq *q, pid_t pid)
{
	if (q->wht_cmd == 2)
		ms_echo(q->cmd_args, pid);
	else if (q->wht_cmd == 3)
		cd(q->cmd_args, s, pid);
	else if (q->wht_cmd == 4)
		pwd(pid);
	else if (q->wht_cmd == 5)
		ms_export(s, q, pid, 1);
	else if (q->wht_cmd == 6)
		ms_unset(s, q, pid, 1);
	else if (q->wht_cmd == 7)
		ms_env(s, q, pid);
	else if (q->wht_cmd == 8)
		ms_exit(s, q, pid);
}
