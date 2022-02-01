/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:53:05 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/02/01 13:52:03 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	Overview in this File:
		create the execution of the commands "env"
	--env--
		display the environmental variables, including those changes by "export" and "unset"
		only display if a <key>=<value> structure is apparent

		Arguments or Flags should not be handeled

		we now use lists to store key and value seperately and to have flags on whether it is to be printed or only stored etc
				-> edge case of unset && cd || echo

		normal print status is (export)			1
		unsetting PWD or HOME switches print to	0
		cd (if currently 0) sets HOME or PWD to	2		so that it doesn't show up in env, but can be used as a Var
*/

t_list	*new_envar(char *input, int flag)
{
	t_envar	*content;
	t_list	*new;

	content = malloc(sizeof(t_envar));
	if (ft_strchr(input, '='))
	{
		content->key = ft_substr(input, 0, ft_strchr(input, '=') - input);
		content->value = ft_strdup(ft_strchr(input, '=') + 1);
		content->print = 1;
	}
	else
	{
		content->key = ft_substr(input, 0, ft_strlen(input));
		content->value = NULL;
		content->print = 0;
	}
	if (flag > 0)
		content->print = flag;
	new = ft_lstnew(content);
	return (new);
}

t_list	*copy_env(char **env)
{
	int		i;
	t_list	*my_env;
	t_list	*next;

	i = 0;
	my_env = NULL;
	while (env[i])
	{
		next = new_envar(env[i], -1);
		if (my_env)
			ft_lstadd_back(&my_env, next);
		else
			my_env = next;
		i++;
	}
	return (my_env);
}

int	display_env(t_list	*env, char dev)
{
	t_list	*temp;
	t_envar	*c;

	temp = env;
	while(temp)
	{
		c = (t_envar *)temp->content;
		if ((dev == 'p' || dev == 'a') && c->value && c->print == 1)
			printf("%s=%s\n", c->key, c->value);
		else if (dev == 'a' && c->value && c->print == 0)
			printf("HIDDEN	%s=%s\n", c->key, c->value);
		temp = temp->next;
	}
	return (0);
}


t_envar	*msh_getenv(t_list *env, char *key)
{
	t_list	*tmp;
	int		diff;

	tmp = env;
	while(tmp)
	{
		diff = ft_strncmp(key, ((t_envar *)tmp->content)->key, ft_strlen(((t_envar *)tmp->content)->key));
		if (diff == 61 || diff == 0)
			return ((t_envar *)tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}


void	ms_env(t_seq *q, t_shell *s)
{
	display_env(s->env, 'p');
}

//#################################

//export

void	disp_env(t_list *org)
{
	t_list	*tmp;
	char	**cpy;
	int		i;

	i = 0;
	tmp = org;
	while(tmp)
	{
		i++;
		tmp = tmp->next;
	}
	cpy = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	tmp = org;
	while(tmp)
	{
		i++;
		cpy[i] = ft_calloc(ft_strlen(((t_envar *)(tmp->content))->key) + ft_strlen(((t_envar *)(tmp->content))->value) + 2, sizeof(char));
		ft_strlcpy(cpy[i], ((t_envar *)(tmp->content))->key, ft_strlen(((t_envar *)(tmp->content))->key));
		cpy[i][ft_strlen(cpy[i])] = '=';
		ft_strlcpy(ft_strchr(cpy[i], '='), ((t_envar *)(tmp->content))->value, ft_strlen(((t_envar *)(tmp->content))->value));
		tmp = tmp->next;
	}
}

t_

int	msh_export(t_seq *q, t_shell *s)
{
	int		i;
	t_list	*tmp;
	t_envar *content;

	if (!q->cmd.cmd_args[0] || q->cmd.cmd_args[0][0] == '#')
	{
		// disp_sorted(s->env);
		return (0);
	}
	i = 0;
	while (q->cmd.cmd_args[i])
	{
		if (key_error(q->cmd.cmd_args[i]))
			printf("bash: export: `%s'not a valid identifier\n", q->cmd.cmd_args[i]);
		else
		{
			tmp = s->env;
			while (tmp && ft_strncmp(q->cmd.cmd_args[i], ((t_envar *)(tmp->content))->key, ft_strlen(((t_envar *)(tmp->content))->key + 1)) != 61)
				tmp = tmp->next;
			if (tmp)
			{
				if (((t_envar *)(tmp->content))->value && ft_strchr(q->cmd.cmd_args[i], '='))
					free (((t_envar *)(tmp->content))->value);
				((t_envar *)(tmp->content))->value = ft_strdup(ft_strchr(q->cmd.cmd_args[i], '=') + 1);
			}
			else
			{
				ft_lstadd_back(&s->env, new_envar(q->cmd.cmd_args[i], -1));
			}
		}
		i++;
	}
}

void	delvar(void *rmv)
{
	t_envar	*c;

	c = ((t_list *)rmv)->content;
	if (c->key)
		free (c->key);
	if (c->value)
		free (c->value);
}

int	create_env(char **env, t_shell *s)
{
	s->env = copy_env(env);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	s;

	if (argc != 1 || argv[1])
		return(2);
	create_env(env, &s);

	t_seq	*q = ft_calloc(1, sizeof(t_seq));

	//	test the functionality of env
	q->cmd.cmd_args = ft_split("lal= me=", ' ');
	ms_env(q, &s);
	display_env(s.env, 'a');
	free(q->cmd.cmd_args);
	q->cmd.cmd_args = ft_split("lal=heh lel", ' ');
	ms_export(q, &s);
	
	free(q);
	//ft_lstclear(&s.env, delvar);
	return(0);
}