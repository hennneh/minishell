/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:08:49 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:08:51 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief function that changes the global error code
 * @param error [int] new error value
 * @param sub	[char*] allocated substitute char in message
 * @param msg	[char*] eventual message
 * -> minishell: command: argument: msg
 * sub = strjoin(command + argument)
 * @param p		[int]	printability (parents don't print)
 * @return [void]
*/
void	ms_error(int error, char *sub, char *msg, int p)
{
	g_errnum = ((unsigned short) error);
	if (msg)
	{
		if (p != 0)
		{
			write(2, "minishell: ", 11);
			write(2, sub, ft_strlen(sub));
			write(2, ": ", 2);
			write(2, msg, ft_strlen(msg));
		}
		if (sub)
			free(sub);
	}
}

void	cleanup_env(t_list *l)
{
	t_list	*tmp;
	t_list	*t;

	tmp = l;
	while (tmp != NULL)
	{
		t = tmp->next;
		delvar(tmp);
		tmp = t;
	}
}

void	clean_exit(t_shell *s)
{
	if (s && s->seq)
		clean_seq(s);
	if (s && s->env)
		cleanup_env(s->env);
	if (s && s->input)
		free(s->input);
}

/**
 * @brief clean and exit the shell
 * @param s [t_shell*] shell
 * @param q [t_seq*]	sequence
 * @param pid [pid_t]	child-or-not pid
 * arguments: if the first argument is not numeric, specific error
 * 			if it has more than 1 argument, different error, no exit
 * 			no argument -> exit (g_err_num)
 * 			one numeric argument -> exit(argument)
*/
int	ms_exit(t_shell *s, t_seq *q, pid_t pid)
{
	if (q && q->cmd_args[1])
	{
		if (ft_isnumeric(q->cmd_args[1]))
			ms_error(255, ft_strjoin("exit: ", q->cmd_args[1]), \
			"numeric argiment required\n", (int)pid);
		else if (q->cmd_args[2])
		{
			ms_error(1, ft_strjoin("exit", ""),
				"too many arguments\n", (int)pid);
			return (g_errnum);
		}
		else
			g_errnum = ft_atoi(q->cmd_args[1]) % 256;
	}
	clean_exit(s);
	if (pid)
	{
		waitpid(pid, NULL, 0);
		printf("exit\n");
		close_fd();
	}
	exit(g_errnum);
}
