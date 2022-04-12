/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:08:42 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:08:44 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief transform the given string into a usable list content for the env
 * @param p_var [char*] line from the original environment or new input
 * @return [t_cont*]
*/
t_cont	*envar(char *p_var)
{
	int		i;
	char	*eq;
	t_cont	*var;

	var = malloc(sizeof(t_cont));
	eq = ft_strchr(p_var, '=');
	if (eq)
	{
		i = ft_strlen(p_var) - ft_strlen(eq);
		var->key = ft_calloc(i + 3, sizeof(char));
		ft_strlcpy(var->key, p_var, i + 1);
		var->value = ft_strdup(p_var + i + 1);
	}
	else
	{
		var->key = ft_strdup(p_var);
		var->value = ft_strdup("");
	}
	return (var);
}

/**
 * @brief delete listelemets from a list with t_cont content type
 * @param elem [t_list*] element to free
 * @return [void]
*/
void	delvar(t_list *elem)
{
	t_cont	*var;

	if (elem)
	{
		var = elem->content;
		if (var)
		{
			if (var->key)
				free(var->key);
			if (var->value)
				free(var->value);
			free(var);
		}
		free(elem);
	}
}

/**
 * @brief set up a list type copy of the given environment
 * @param p_env [char**] original environment
 * @return [t_list*]
*/
t_list	*create_env(char **p_env)
{
	int		i;
	t_list	*env;

	if (!p_env[0])
		return (NULL);
	env = ft_lstnew((void *)envar(p_env[1]));
	i = 2;
	while (p_env[i])
	{
		ft_lstadd_back(&env, ft_lstnew(envar(p_env[i])));
		i++;
	}
	return (env);
}

/**
 * @brief display env variables if they have values
 * @param s [t_shell*] shell
 * @param q [t_seq*]	sequence
 * @param pid [pid_t]	child-or-not pid
 * @return [void]
*/
void	ms_env(t_shell *s, t_seq *q, pid_t pid)
{
	t_list	*temp;

	if (q->cmd_args[1] && !pid)
	{
		ms_error(127, ft_strjoin("env: ", q->cmd_args[1]),
			"invalid use of function", pid);
		return ;
	}
	temp = s->env;
	while (temp)
	{
		if (((t_cont *)temp->content)->value[0] && !pid)
			printf("%s=%s\n", ((t_cont *)temp->content)->key, \
							((t_cont *)temp->content)->value);
		temp = temp->next;
	}
	g_errnum = 0;
}

/**
 * @brief copy the environment into a string array
 * @param p_env [t_list*] envitonment of our shell
 * @return [char**]
*/
char	**env_copy(t_list *p_env)
{
	char	**env;
	t_list	*temp;
	int		i;

	temp = p_env;
	i = 0;
	env = ft_calloc((ft_lstsize(p_env) + 1), sizeof(char *));
	while (i < ft_lstsize(p_env))
	{
		env[i] = ft_calloc(ft_strlen(((t_cont *)temp->content)->key) + \
							ft_strlen(((t_cont *)temp->content)->value) + 5, 1);
		ft_strlcpy(env[i], ((t_cont *)temp->content)->key, \
							ft_strlen(((t_cont *)temp->content)->key) + 1);
		env[i][ft_strlen(env[i])] = '=';
		ft_strlcpy(env[i] + ft_strlen(env[i]), ((t_cont *)temp->content)->\
								value, ft_strlen(((t_cont *)temp->content)->\
																value) + 1);
		temp = temp->next;
		i++;
	}
	return (env);
}
