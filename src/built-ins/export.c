/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:08:56 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:08:57 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief sort a list of n strings by ascii value
 * @param plist [char***] pointer to string-array
 * @param n [int] numer of string
*/
void	sort_list(char ***plist, int n)
{
	int		i[2];
	char	*tmp;
	char	**list;

	list = *plist;
	i[0] = 0;
	i[1] = 0;
	while (i[0] < n && list[i[0]] && list[i[0] + 1])
	{
		if (list[i[0]][i[1]] == list[i[0] + 1][i[1]])
			i[1]++;
		else if (list[i[0]][i[1]] < list[i[0] + 1][i[1]])
		{
			i[0]++;
			i[1] = 0;
		}
		else if (list[i[0]][i[1]] > list[i[0] + 1][i[1]])
		{
			tmp = list[i[0]];
			list[i[0]] = list[i[0] + 1];
			list[i[0] + 1] = tmp;
			i[0] = 0;
			i[1] = 0;
		}
	}
}

/**
 * @brief free an array of strings
 * @param list [char**] array to free
*/
void	del_list(char **list)
{
	int	i;

	i = 0;
	while (list && list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

/**
 * @brief display all environment variables with a prefix and sorted
 * @param env [t_list*] our environment
 * @return [void]
*/
void	export_all(t_list *env)
{
	char	**c_env;
	int		i;
	char	*tmp;

	c_env = env_copy(env);
	sort_list(&c_env, ft_lstsize(env));
	i = 0;
	while (c_env[i])
	{
		c_env[i] = ft_realloc(c_env[i], ft_strlen(c_env[i]), 3);
		if (!ft_strchr(c_env[i], '='))
			printf("declare -x %s\"\"\n", c_env[i]);
		else
		{
			tmp = ft_strchr(c_env[i], '=');
			ft_memmove(tmp + 1, tmp, ft_strlen(tmp));
			*tmp = '=';
			*(tmp + 1) = '"';
			c_env[i][ft_strlen(c_env[i])] = '"';
			printf("declare -x %s\n", c_env[i]);
		}
		i++;
	}
	del_list(c_env);
	g_errnum = 0;
}

/**
 * @brief find and return the pointer of an element of our env
 * @param env [t_list*] our shells environment
 * @param key [char*] identifier of the searched element
 * @return [t_list*] found element or NULL
*/
t_list	*finder(t_list *env, char *key)
{
	t_list	*temp;
	int		klen;

	if (ft_strchr(key, '='))
		klen = ft_strlen(key) - ft_strlen(ft_strchr(key, '='));
	else
		klen = ft_strlen(key) + 1;
	temp = env;
	while (temp)
	{
		if (!ft_strncmp(key, ((t_cont *)temp->content)->key, klen))
		{
			break ;
		}
		temp = temp->next;
	}
	return (temp);
}

/**
 * @brief add or update variables to the environment
 * @param s [t_shell*] shell
 * @param q [t_seq*]	sequence
 * @param pid [pid_t]	child-or-not pid
 * @param i [int] always 1, too many lines
*/
void	ms_export(t_shell *s, t_seq *q, pid_t pid, int i)
{
	t_list	*new;

	if (!q->cmd_args[1] && !pid)
		return (export_all(s->env));
	while (q->cmd_args[i])
	{
		new = finder(s->env, q->cmd_args[i]);
		if (keyer(q->cmd_args[i]))
			ms_error(1, ft_strjoin("export: ", q->cmd_args[i]),
				"not a valid identifier\n", (int)pid);
		else if (new)
		{
			free(((t_cont *)new->content)->value);
			if (ft_strchr(q->cmd_args[i], '='))
				((t_cont *)new->content)->value = \
				ft_strdup(ft_strchr(q->cmd_args[i], '=') + 1);
			else
				((t_cont *)new->content)->value = ft_strdup("");
		}
		else
			ft_lstadd_back(&s->env, ft_lstnew(envar(q->cmd_args[i])));
		i++;
	}
	g_errnum = 0;
}
