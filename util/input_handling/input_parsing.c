/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:18:17 by vheymans          #+#    #+#             */
/*   Updated: 2022/02/01 21:15:34 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
**each seq cmds/actions that are sperated by '|'
**each part of the seq can be either:
**		-input
**		-action (cmd or flags...)
**		-output
**the 'action' needs to be done to each input and outputed to each output
*/

/*
**init cmd figures out what cmd is passed and the path
** 0 == shell cmd; 1 == ERROR 2 == echo; 3 == cd; 4 == pwd; 5 == export
** 6 == unset; 7 == env; 8 == exit; 9 == $?; ?9 == CTRL?
*/

int	init_cmd(t_seq *seq, char **path)// dont have CTRL, still need argument parsing for our functions
{
	if (ft_strnstr(seq->seq, "echo", 4))
		seq->wht_cmd = 2;
	else if (ft_strnstr(seq->seq, "cd", 2))
		seq->wht_cmd = 3;
	else if (ft_strnstr(seq->seq, "pwd", 3))
		seq->wht_cmd = 4;
	else if (ft_strnstr(seq->seq, "export", 6))
		seq->wht_cmd = 5;
	else if (ft_strnstr(seq->seq, "unset", 5))
		seq->wht_cmd = 6;
	else if (ft_strnstr(seq->seq, "env", 3))
		seq->wht_cmd = 7;
	else if (ft_strnstr(seq->seq, "exit", 4))
		seq->wht_cmd = 8;
	else if (ft_strnstr(seq->seq, "$?", 2))
		seq->wht_cmd = 9;
	return (cmd_new(seq, path));
}

/*
**init_fd finds if there is a input or output file for the cmd
*/

int	init_fd(t_seq *seq, char **sp) //still needs an to check if the fd are valid // also need to do some closing
{
	int	i;

	i = 0;
	while (sp[i])
	{
		if (sp[i][0] == '<')
		{printf("[%s]\n", trim_whitespace(ft_strtrim(sp[i], "<"), 2));
			if (!access(trim_whitespace(ft_strtrim(sp[i], "<"), 2), F_OK))
				seq->fd[0] = open(trim_whitespace(ft_strtrim(sp[i], "<"), 2), O_RDONLY, 0777);
			else
				return (1);
		}
		else if (sp[i][0] == '>')
		{
			seq->fd[1] = open(trim_whitespace(ft_strtrim(sp[i], ">"), 2), O_WRONLY | O_CREAT | O_TRUNC, 0777);
		}
		i ++;
	}
	return (0);
}

int	init_seq(t_seq *seq, char **env)
{
	seq->fd[0] = STDIN_FILENO;
	seq->fd[1] = STDOUT_FILENO;
	printf("init_done\n");
	seq->wht_cmd = 0;
	if (cmd_split(seq->seq, seq))
	{
		ft_error("SPLIT ERROR", STDERR_FILENO);
		return (1);
	}
	for(int i = 0; seq->split[i]; i ++)
		printf("[%d] : [%s]\n", i , seq->split[i]);
	printf("done cmd split\n");
	if (init_fd(seq, seq->split))
	{
		ft_error("Error accessing the input or output files", STDERR_FILENO); //ERROR
		return (1);
	}
	printf("done fd \n");
	if (init_cmd(seq, ft_path(env)))
	{
		ft_error("CMD ERROR", STDERR_FILENO);
		return (1);
	}
	printf("done init seq\n");
	return (0);
}

/*int	shell_t(char **env)
{
	t_shell s;

	s.env = env;
	s.pwd = getenv("PWD=");
	while (1)
	{
		dup2(0, STDIN_FILENO);
		dup2(1, STDOUT_FILENO);
		s.input = readline(ft_strjoin(s.pwd, "$ "));
		if (!ft_strncmp(s.input,"END", 3))
			break ;
		s.n_cmds = 0;
		pipe_split(&s, s.input);
		int i = 0;
		while (i < s.n_cmds)
		{
			printf("start while\n");
			init_seq(s.seq[i], s.env);
			printf("init seq done\n");
			dup2(s.seq[i]->fd[0], STDIN_FILENO);
			dup2(s.seq[i]->fd[1], STDOUT_FILENO);
			for (int x = 0; s.seq[i]->split[x]; x++)
				printf("path cmd = %s\n", s.seq[i]->split[x]);// SEG fault
			// int pid = fork();
			// if (!pid)
			// 	execve(s.seq[i]->cmd.path_cmd, s.seq[i]->cmd.cmd_args, env);
			// else 
			// 	waitpid(pid, NULL, 0);
			i ++;
			write(1, "DONE\n", 5);
		}
	}
	printf("done shell\n");
	return (0);
}*/
