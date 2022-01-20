/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:53:05 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/01/19 19:27:39 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	Overview in this File:
		create the execution of the commands "env"
	--env--
		display the environmental variables, including those changes by "export" and "unset"
		only display if a <key>=<value> structure is apparent
		if given an argument, see it as path from where to display its environment, (mostly "<input> : Permission deined")
		however if the argument has an '=' symbol, print it at the end of the environment, but don't add it
		mutiple arguments count, as long as they declare <key>=<value> no naming specifications (all ascii possible)
		env does not interact with input files
*/

void	disp_env(t_shell *s)
{
	int	i;

	i = 0;
	while (s->env[i])
	{
		if (ft_strchr(s->env[i], '='))
			printf("%i\t%s\n", i, s->env[i]);
		i++;
	}
}

void	ms_env(t_seq *q, t_shell *s)
{
	int	i;

	i = 0;
	while (q->cmd.cmd_args[i])
	{
		if (!ft_strchr(q->cmd.cmd_args[i], '='))
		{
			printf("env : %s: No such file or directory\n", q->cmd.cmd_args[i]);
			return ;
		}
		if (q->cmd.cmd_args[i][0] == '=')
		{
			printf("env : setenv: %s: Invalid argument\n", q->cmd.cmd_args[i]);
			return ;
		}
		i++;
	}
	i = 0;
	while (s->env[i])
	{
		if (ft_strchr(s->env[i], '='))
			printf("%s\n", s->env[i]);
		i++;
	}
	i = 0;
	while (q->cmd.cmd_args[i])
	{
		printf("%s\n", q->cmd.cmd_args[i]);
		i++;
	}
}

//	a function to extract the value of an environmental variable
char	*ms_getenv(char *key, t_shell *s)
{
	int	p;

	p = keyfinder(key, ft_strlen(key), s->env);
	if (p >= 0)
		return (s->env[p + ft_strlen(key) + 1]);
	else
		return (NULL);
}

// int	main(int argc, char **argv, char **env)
// {
// 	t_shell	s;

// 	if (argc != 1 || argv[1])
// 		return(2);
// 	create_env(env, &s);
// 	// disp_env(&s);

// 	t_seq	*q = ft_calloc(1, sizeof(t_seq));

// 	//	test the functionality of env
// 	q->cmd.cmd_args = ft_split("lal= me= =", ' ');
// 	ms_env(q, &s);
// 	free(q->cmd.cmd_args);
// 	// q->cmd.cmd_args = ft_split("#", ' ');
// 	// ms_export(q, &s);
	
// 	free(q);
// 	return(0);
// }