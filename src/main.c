/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:08:08 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:08:10 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * Main Shell Function
 * @param env [char **] envroment 
 * @return [int] 0 if successfull
*/
int	shell(char **env)
{
	t_shell	s;

	init_sig();
	s.env = create_env(env);
	while (1)
	{
		s.input = readline(PROMPT);
		if (!s.input)
			break ;
		add_history(s.input);
		interpret(&s, &s.input);
		if (!extract_cmd(&s))
			launch_cmd(&s);
		free(s.input);
	}
	exit(0);
	return (0);
}

/**
 * Main Function
 * runs the shell function if # of args is 1 and that it is "./minishell".
 * Else returns error
 * @param argc	[int] number of arguments
 * @param argv	[char **] arguments
 * @param env	[char **] enviroment
 * @return 0 if succesfull, non-zero if error
*/
int	main(int argc, char **argv, char **env)
{
	g_errnum = 0;
	if (argc != 1 && strncmp(argv[0], "./minishell", strlen(argv[0])))
	{
		printf("No Arguments required\n");
		return (0);
	}
	shell(env);
	return (0);
}
