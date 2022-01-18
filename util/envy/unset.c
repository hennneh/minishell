/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:53:05 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/01/18 16:44:19 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	Overview in this File:
		create the execution of the commands "unset"
	--unset--
		remove environmental variables specified by a <key> from the set of environmental variables
		no matter if it has a value; 
		if an '=' is in the argument, the current executuion interrupts with the error "invalid parameter name"
		if the <key> does not apply to the naming convention as in "export" the error: "not a valid identifier"
		if no argument is given the error message is "not enough arguments"
*/

int	ms_unset(t_seq *q, t_shell *s)
{
	int		i;
	int		c;
	int		o;
	char	**new;

	if (!q || !s)
		return 1;
	if (!q->cmd.cmd_args[0])
	{
		printf("unset: not enough arguments\n");
		return (0);
	}
	i = 0;
	while (q->cmd.cmd_args[i])
	{
		if (ft_strchr(q->cmd.cmd_args[i], '='))
		{
			printf("unset: `%s': invalid parameter name\n", q->cmd.cmd_args[i]);
			return (1);
		}
		if (key_error(q->cmd.cmd_args[i]))
		{
			printf("unset: `%s': not a valid identifier\n", q->cmd.cmd_args[i]);
			return (1);
		}
		if (keyfinder(q->cmd.cmd_args[i], ft_strlen(q->cmd.cmd_args[i]), s->env) >= 0)
		{
			new = ft_calloc(outerlen(s->env), sizeof(char *));
			c = 0;
			o = 0;
			while (new[c])
			{
				if (c == keyfinder(q->cmd.cmd_args[i], ft_strlen(q->cmd.cmd_args[i]), s->env))
				{
					free(s->env[c]);
					o = 1;
				}
				new[c] = s->env[c + o];
				c++;
			}
			free(s->env);
			s->env = new;
		}
		
	}
	return (0);
}

/*

int	main(int argc, char **argv, char **env)
{
	t_shell	s;

	if (argc != 1 || argv[1])
		return(2);
	create_env(env, &s);
	// disp_env(&s);

	t_seq	*q = ft_calloc(1, sizeof(t_seq));

	//	test the functionality of unset
	q->cmd.cmd_args = ft_split("lal=100 meme=lal meh", ' ');
	ms_export(q, &s);
	free(q->cmd.cmd_args);
	q->cmd.cmd_args = ft_split("lal meme meh", ' ');
	ms_unset(q, &s);
	free(q->cmd.cmd_args);
	q->cmd.cmd_args = ft_split("#", ' ');
	ms_export(q, &s);
	
	free(q);
	return(0);
}

*/
