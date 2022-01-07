/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:41:05 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/05 11:27:22 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**adds a '/' to the end of line in a array
*/

int	ft_add_slash(char **array)
{
	int		x;
	char	*temp;

	x = 0;
	while (array[x])
	{
		temp = ft_strjoin(array[x], "/");
		free(array[x]);
		array[x] = temp;
		x ++;
	}
	return (0);
}

/*
**get_path frees the previous path if it exists and finds the local paths.
**Returns in a ** str with a slash
*/

char	**get_path(char **path)
{
	if (path)
	{
		if (path[0])
			free_2dstr(path);
		else
			free(path);
	}
	path = ft_split(getenv("PATH"), ':');
	if (!path)
		return (NULL);
	ft_add_slash(path);
	return (path);
}
