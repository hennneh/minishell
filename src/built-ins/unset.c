/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:09:21 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:09:22 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief check if the given char* fits the name reqirements of env variables
 * @param input [char*]
 * @return [int] 0->passes 1->fails
*/
int	keyer(char *input)
{
	int	i;

	i = 0;
	if (!ft_isalpha(input[i]) && input[i] != '_')
		return (1);
	while (input[i] && input[i] != '=')
	{
		if (!ft_isalnum(input[i]) && input[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief remove variables to the environment
 * @param s [t_shell*] shell
 * @param q [t_seq*]	sequence
 * @param pid [pid_t]	child-or-not pid
 * @param i [int] always 1 
*/
void	ms_unset(t_shell *s, t_seq *q, pid_t pid, int i)
{
	t_list	*new;
	t_list	*tmp;

	while (q->cmd_args[i])
	{
		new = finder(s->env, q->cmd_args[i]);
		if ((keyer(q->cmd_args[i]) || ft_strchr(q->cmd_args[i], '=')) && !pid)
			ms_error(1, ft_strjoin("unset: ", q->cmd_args[i]),
				"not a valid identifier\n", (int)pid);
		else if (new)
		{
			tmp = s->env;
			if (tmp == new)
				s->env = tmp->next;
			else
			{
				while (tmp->next != new)
					tmp = tmp->next;
				tmp->next = new->next;
			}
			delvar(new);
		}
		i++;
	}
	g_errnum = 0;
}

/**
 * @brief get a line consisting of key and value and return the env
 * 			element, if it exists
 * @param env [t_list*] our environment
 * @param line [char*] the input to search part of for
*/
t_list	*de_key(t_list *env, char *line)
{
	int		i;
	char	*key;
	t_list	*res;

	i = 0;
	if (!(ft_isalpha(line[0]) || line[0] == '_'))
		return (NULL);
	while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
		i++;
	key = ft_substr(line, 0, i);
	res = finder(env, key);
	free(key);
	return (res);
}
