/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:46:33 by hlehmann          #+#    #+#             */
/*                                                                            */                  
/*   Updated: 2022/01/18 16:42:41 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		shell(char **env)
{
	t_shell	s;

	create_env(env, &s); // changed by Hamdrik
	//prompt(s);
//	s.pwd = get_pwd(); // Hendrik
	while (1)
	{
		// s.input = readline(s.pwd);
		// if (s.input)
		// {
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
	shell_t(env);
	return (0);
}
