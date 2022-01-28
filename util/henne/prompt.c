/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 07:53:13 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/28 10:21:14 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*prompt(t_shell *s)
{
	char	*prompt;
	char	dir;
	char	*check;

	dir = malloc(sizeof(char) * 1024);
	check = NULL;
	check = getcwd(dir, 1024);
	if (!check)
		return (NULL);
	check = ft_strrchr(dir, '/');
	check++;
	prompt = ft_strjoin("minishell: ", check);
	free(dir);
	return (prompt);
}
