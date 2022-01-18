/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:54:43 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/01/18 16:39:36 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	duplicate the system-environment and store the copy in the given shell
int	create_env(char **sysenv, t_shell *s)
{
	int		i;
	int		l;

	l = 0;
	while (sysenv[l])
		l++;
	s->env = ft_calloc((l + 1), sizeof(char *));
	if (!s->env)
		return (1);
	i = 0;
	while (i < l)
	{
		s->env[i] = ft_strdup(sysenv[i]);
		if (!s->env[i])
			return (1);
		i++;
	}
	return (0);
}

//	return the number of lines in a list
size_t	outerlen(char **list)
{
	int i;

	i = 0;
	while(list && list[i])
	{
		i++;
	}
	return (i);
}

//	search the key in a list of key;value and return the line number (start 0)
int	keyfinder(char *key, int keylen, char **list)
{
	int	i;

	i = 0;
	while (i < outerlen(list))
	{
		if ((ft_strncmp(key, list[i], keylen) == 0) && \
			(!list[i][keylen] || list[i][keylen] == '='))
			return (i);
		i++;
	}
	return (-1);
}

//	check if the givien variable key complys to the char norms
int	key_error(char *input)
{
	int	i;

	i = 0;
	if (!ft_isalpha(input[0]) && input[i] != '_')
		return (1);
	while (input[i] && input[i] != '=')
	{
		if (!ft_isalnum(input[i]) && input[i] != '_')
			return (1);
		i++;
	}
	return (0);
}
