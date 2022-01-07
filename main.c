/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:46:33 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/07 15:37:01 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell(char **env)
{
	t_shell	s;

	s.env = env; // changed by Hamster
	s.pwd = get_pwd(); // Hendrick
	while (1)
	{
		s.input = readline(s.pwd);
		if (s.input)
		{
			s.his = add_input_his(s.input, s.his); // Hendrik
			read_input(s.input, s.cmds, s); // Vincent
			analyse_inputs(s.cmds); // Vincent
			exec_inputs(s.cmds); // Vincent & Kostas
		}
		else if (!s.input)
			exit_shell(&s); // Hamster
		free(s.input);
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
