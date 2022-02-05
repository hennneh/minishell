/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:46:33 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/05 17:13:54 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell(char **env)
{
	t_shell	s;

	create_env(env, &s);
	//prompt(s);
	s.pwd = "GIMMY SOMETHING >";//get_cwd(); // Hendrik
	while (1)
	{
		s.in = dup(STDIN_FILENO);
		s.out = dup(STDOUT_FILENO);
		s.input = readline(prompt());
		if (s.input)
		{
			if (check_quotes(s.input))
				ft_error("unequal nmbr of quotes\n", STDERR_FILENO);
			if (ft_strchr(s.input, '$'))
				replace_vars(&s);
			add_history(s.input);
			if (!ft_strncmp(s.input, "EXIT", 4))
				exit(0);
			s.n_cmds = 0;
			int i = 0;
			if (pipe_split(&s, s.input))
				ft_error("syntax error near unexpected token `|'", STDERR_FILENO);
			while (i < s.n_cmds)
			{
				init_seq(s.seq[i], s.env, &s);
				dup2(s.seq[i]->fd[0], STDIN_FILENO);
				dup2(s.seq[i]->fd[1], STDOUT_FILENO);
				int pid = fork();
				if (!pid)
					execve(s.seq[i]->path_cmd, s.seq[i]->cmd_args, env);
				else
					waitpid(pid, NULL, 0);
				i ++;
				printf("done %d\n", i);
			}
		}
		// 	s.his = add_input_his(s.input, s.his); // Hendrik
		// 	read_input(s.input, s.seq, s); // Vincent
		// 	analyse_inputs(s.seq); // Vincent
		// 	exec_inputs(s.seq); // Vincent & Kostas
		// }
		// else if (!s.input)
		// 	exit_shell(&s); // Hamster
		// free(s.input);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 1 && strncmp(argv[0], "./minishell", strlen(argv[0])))
		ft_error("fuck", 2);
	shell(env);
	return (0);
}
