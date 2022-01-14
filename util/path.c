/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:41:05 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/13 17:43:25 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_path(char **path, char **cmd)
{
	int		x;
	char	*temp;

	x = 0;
	while (path[x])
	{
		temp = ft_strjoin(path[x], *cmd);
		if (!access(temp, X_OK) && !access(temp, F_OK))
			return (temp);
		free(temp);
		x ++;
	}
	return (NULL);
}

/*
**Creates the 2d array containing all the possible paths
*/

char	**ft_path(char **env)
{
	int		x;
	char	**path;

	x = 0;
	path = NULL;
	while (env[x])
	{
		if (ft_strnstr(env[x], "PATH=", 5))
		{
			path = ft_split(ft_strnstr(env[x], "PATH=", 5), ':');
			break ;
		}
		x ++;
	}
	if (!path)
		return (NULL);
	ft_add_slash(path);
	return (path);
}

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
