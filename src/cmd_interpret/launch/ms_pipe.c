/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:10:36 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:10:37 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_pipe_parent(pid_t pid, t_shell *sh, t_seq *seq, int *fd)
{
	int	status;

	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		write(1, "dup2 Parent failed\n", 19);
	is_running(pid);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_errnum = WEXITSTATUS(status);
	is_running(-1);
	ms_exec_builtins(sh, seq, pid);
	close(fd[0]);
}

void	ft_pipe_last(t_shell *sh, t_seq *seq, int s_fd[2])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd))
		write(2, "Pipe Falure\n", 12);
	pid = fork();
	if (pid < 0)
		write(2, "The Fork failed\n", 16);
	if (!pid)
	{
		close(fd[0]);
		if (dup2(s_fd[1], STDOUT_FILENO) == -1)
			write(1, "dup2 Child failed\n", 18);
		signal(SIGINT, sig_handler_child);
		ms_exec_builtins(sh, seq, pid);
		exit(127);
	}
	else
	{
		ft_pipe_parent(pid, sh, seq, fd);
	}
}

void	ft_pipe(t_shell *sh, t_seq *seq)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd))
		write(2, "Pipe Falure\n", 12);
	pid = fork();
	if (pid < 0)
		write(2, "The Fork failed\n", 16);
	if (!pid)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			write(1, "dup2 Child failed\n", 18);
		signal(SIGINT, sig_handler_child);
		ms_exec_builtins(sh, seq, pid);
		exit(127);
	}
	else
	{
		ft_pipe_parent(pid, sh, seq, fd);
	}
}
