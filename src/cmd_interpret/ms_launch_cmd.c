/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_launch_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:09:45 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:09:46 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * Creates a tmp fd to hold STDIN_FILENO and STDOUT_FILENO
 * while not the last seq, run ft_pipe
 * if last seq, run ft_pipe_last
 * dup2 tmp fd back into STDIN_FILENO and STDOUT_FILENO
 * close tmp fds and clean/free sh
 * @param sh [t_shell *] shell struct
 * @return 0 for success
*/
int	launch_cmd(t_shell *sh)
{
	int	tmp_fd[2];
	int	i;

	tmp_fd[0] = dup(0);
	tmp_fd[1] = dup(1);
	i = 0;
	while (i < sh->n_cmds - 1 && !g_errnum)
	{
		if (dup2(sh->seq[i]->fd[0], STDIN_FILENO) == -1 || \
			dup2(sh->seq[i]->fd[1], STDOUT_FILENO) == -1)
		{
			g_errnum = -1;
			return (write(tmp_fd[1], "dup2 Top failed\n", 16));
		}
		ft_pipe(sh, sh->seq[i]);
		i ++;
	}
	ft_pipe_last(sh, sh->seq[i], sh->seq[i]->fd);
	dup2(tmp_fd[0], STDIN_FILENO);
	dup2(tmp_fd[1], STDOUT_FILENO);
	close(tmp_fd[0]);
	close(tmp_fd[1]);
	clean_seq(sh);
	close_fd();
	return (0);
}
