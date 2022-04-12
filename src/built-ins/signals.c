/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:09:14 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:09:16 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signum == SIGINT)
		sigint_handler(signum);
}

/**
 * @brief outsource the sinal action in order to prevent parent signals
 * @param signum [int] recieved signal
*/
void	sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		if (is_running(0) != 0)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
	else if (signum == SIGQUIT)
	{
		printf("\b\b");
		return ;
	}
}

int	is_running(pid_t pid)
{
	static pid_t	id;

	if (pid == 0 && id != 0)
	{
		kill(id, 2);
		id = pid;
	}
	else if (pid > 0)
		id = pid;
	else if (pid == -1)
		id = 0;
	else
		return (-1);
	return (id);
}

void	sig_handler_child(int signum)
{
	(void) signum;
	printf("child is exit\n");
	exit(0);
}

void	init_sig(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sighandler;
	sigaction(SIGINT, &sig, NULL);
	signal(SIGQUIT, SIG_IGN);
}
