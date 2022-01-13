/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternate_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:18:17 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/12 15:15:14 by vheymans         ###   ########.fr       */
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
**init_fd finds if there is a input or output file for the cmd
*/

int	init_fd(t_seq *seq, char *split, int fd)
{
	char	*s;
	char	c;

	if (fd == 0)
		c = '<';
	else
		c = '>';
	s = ft_strchr(split, c);
	while (s)
	{
		if (*s + 1 != c)
		{
			if (fd == 0 && !access(ft_strtrim(ft_substr(s + 1, 0, ft_strlen(s + 1) - ft_strlen(find_limitor(s + 1))), " "), F_OK))
				seq->fd[fd] = open(ft_strtrim(ft_substr(s + 1, 0, ft_strlen(s + 1) - ft_strlen(find_limitor(s + 1))), " "), O_RDONLY, 0777);
			if (fd == 1)
				seq->fd[fd] = open(ft_strtrim(ft_substr(s + 1, 0, ft_strlen(s + 1) - ft_strlen(find_limitor(s + 1))), " "), O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (seq->fd[fd] < 0)
				return (1);
			if(access(ft_strtrim(ft_substr(s + 1, 0, ft_strlen(s + 1) - ft_strlen(find_limitor(s + 1))), " "), F_OK))
				return (1);
		}
		if (*s + 1 == c)
			s ++;
		s = ft_strchr(s + 1, c);
	}
	return (0);
}

int	init_seq(t_seq *seq, char *split)
{
	seq->seq = split;
	seq->fd[0] = STDIN_FILENO;
	seq->fd[1] = STDOUT_FILENO;
	if (init_fd(seq, split, 0) || init_fd(seq, split, 1))
	{
		ft_error("Error accessing the input or output files", STDERR_FILENO); //ERROR
		return (1);
	}
	return (0);
}

int	shell_t(char **env)
{
	t_shell s;
	t_seq seq;

	char **split = NULL;
	s.env = env;
	s.pwd = getenv("PWD="); // free in the end
	while (1)
	{
		dup2(0, STDIN_FILENO);
		dup2(1, STDOUT_FILENO);
		s.input = readline(ft_strjoin(s.pwd, "$ "));
		if (!ft_strncmp(s.input,"END", 3))
			break ;
		//printf("input > %s\n", s.input);
		//check_pipe
		//if (ft_strchr(s.input, PIPE)) // initial separation of arguments, need separate function for that
		//{
			split = ft_split(s.input, PIPE);
			int i = 0;
			while (i == 0)
			{
				init_seq(&seq, split[i]);
				dup2(seq.fd[0], STDIN_FILENO);
				dup2(seq.fd[1], STDOUT_FILENO);
				char **cat;
				cat = ft_calloc(sizeof(char *), 2);
				cat[0] = ft_strdup("cat");
				int pid = fork();
				if (!pid)
					execve("/bin/cat", cat, env);
				else 
					waitpid(pid, NULL, 0);
				i ++;
				write(1, "done\n", 5);
			}
		//}
	}
	printf("done\n");
	return (0);
}
