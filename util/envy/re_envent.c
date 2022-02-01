/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_envent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:52:34 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/02/01 20:09:22 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	convert the environment into an char** again for some execve functions
char	**re_envent(t_list *env)
{
	char	**res;
	t_list	*tmp;
	int		i;

	tmp = env;
	i = 0;
	while(tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (!i)
		return (NULL)
	res = ft_calloc(i + 1, sizeof(char *));
	tmp = env;
	i = 0;
	while(tmp)
	{
		res[i] = ft_calloc(ft_strlen(((t_envar *)tmp->content)->key) + ft_calloc(ft_strlen(((t_envar *)tmp->content)->value) + 2, sizeof(char));
		ft_strlcpy(res[i], ((t_envar *)tmp->content)->key, ft_strlen(res[i]));
		if (((t_envar *)tmp->content)->value)
			res[ft_strlen(res[i])] = '=';
		ft_strlcat(res[i], ((t_envar *)tmp->content)->value, ft_strlen(((t_envar *)tmp->content)->value));
		i++;
		tmp = tmp->next;
	}
	return (res);
}

//	free a given double pointerd char
void	free_dbchar(char **frei)
{
	if (!frei || !frei[0])
		return ;
	while (frei[0])
	{
		free (frei[0]);
		frei++;
	}
	free(frei);
}
