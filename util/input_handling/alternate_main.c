/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:18:17 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/08 18:39:01 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	shell(char **env)
{
	t_shell s;

	char **split = NULL;
	s.env = env;
	s.pwd = getenv("PWD="); // free in the end
	while (1)
	{
		s.input = readline(ft_strjoin(s.pwd, "$ "));
		if (!ft_strncmp(s.input,"END", 3))
			break ;
		//printf("input > %s\n", s.input);
		//check_pipe
		if (ft_strchr(s.input, PIPE)) // initial separation of arguments, need separate function for that
		{
			split = ft_split(s.input, PIPE);
			for (int i = 0; split[i]; i++)
				printf("%s\n", split[i]);
		}
		
	}
	return (0);
}
