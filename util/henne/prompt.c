/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 07:53:13 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/28 13:19:49 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*prompt(void)
{
	char	*prompt;
	char	*dir;
	char	*check;

	dir = malloc(sizeof(char) * 1024);
	check = NULL;
	check = getcwd(dir, 1124);
	if (!check)
		return (NULL);
	check = ft_strrchr(dir, '/');
	check++;
	prompt = ft_strjoin("\033[1;32mminishell: \033[0m", check);
	free(dir);
	dir = ft_strjoin(prompt, " $ ");
	free(prompt);
	return (dir);
}
/*
int	main(int argc, char **argv, char **env)
{
	if (argc!= 1 && strncmp(argv[0], "./minishell", strlen(argv[0])))
		write(1, "\n", 1);
	char *c = prompt();
	printf("%s\n", c);
	free(c);
	return (0);
}
*/
