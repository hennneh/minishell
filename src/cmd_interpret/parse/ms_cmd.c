/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:11:02 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:11:04 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*ft_get_path( char **cmd, char **path)
{
	int		x;
	char	*temp;

	x = 0;
	if (!path)
	{
		ms_error(127, ft_strjoin(*cmd, ": Path not found"), "\n", 1);
		return (NULL);
	}
	while (path[x])
	{
		temp = ft_strjoin(path[x], *cmd);
		if (!access(temp, X_OK) && !access(temp, F_OK))
			return (temp);
		free(temp);
		x ++;
	}
	temp = (char *) ft_calloc(ft_strlen(*cmd) + 1, sizeof(char));
	ft_strlcpy(temp, *cmd, ft_strlen(*cmd) + 1);
	if (!access(*cmd, X_OK) && !access(*cmd, F_OK))
		return (temp);
	ms_error(127, ft_strjoin(*cmd, ": command not found"), "\n", 1);
	free(temp);
	return (NULL);
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
/*
**Creates the 2d array containing all the possible paths
*/

char	**ft_path(t_shell *s)
{
	char	**path;
	t_list	*pth;

	pth = finder(s->env, "PATH=");
	if (!pth)
		return (NULL);
	path = ft_split(((t_cont *)pth->content)->value, ':');
	if (!path)
		return (NULL);
	ft_add_slash(path);
	return (path);
}
