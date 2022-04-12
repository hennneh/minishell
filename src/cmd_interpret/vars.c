/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:09:50 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:09:51 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief join two strings, with the second one being inserted into the first 
 * 			at a position and replacing an amount of characters
 * @param line [char*] base string later freed
 * @param add	[char*] inserted string
 * @param pos [int] starting position of the insertion
 * @param skipc [int] number of chars to be replaced
*/
char	*insert_string(char *line, char *add, int pos, int skipc)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_calloc(ft_strlen(line) + ft_strlen(add) + 1, sizeof(char));
	while (i < pos && line[i])
	{
		new[i] = line[i];
		i++;
	}
	i = 0;
	while (add && add[i])
	{
		new[i + pos] = add[i];
		i++;
	}
	i = pos + skipc - 1;
	while (line[i])
	{
		new[ft_strlen(new)] = line[i];
		i++;
	}
	free(line);
	return (new);
}

int	extract_rep(char *line, t_list *env, char **replace)
{
	t_list	*var;
	int		i;

	if (line[0] == '?')
		*replace = ft_itoa(((unsigned short)g_errnum % 256));
	if (line[0] == '0')
		*replace = ft_strdup("minishell");
	if (line[0] == '\0')
		*replace = ft_strdup("$");
	if (line[0] == '0' || line[0] == '?' || line[0] == '\0')
		return (1);
	var = de_key(env, line);
	if (!var)
	{
		*replace = ft_strdup("");
		i = 0;
		while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
			i++;
		return (i);
	}
	*replace = ft_strdup(((t_cont *)var->content)->value);
	return ((int)ft_strlen(((t_cont *)var->content)->key));
}

/**
 * @brief edit the given string and replace indicators of
 * 			variables with the value of the variable
 * @param s [t_shell*] our shell
 * @param line [char**] address of the given line, for reallocation
 * @return [void]
 * 
 * in function	i[0] -> index in line
 * 				i[1] -> status in whether in between quotes
 * 				i[2] -> keylength of the replacement variable
*/
void	interpret(t_shell *s, char **line)
{
	int		i[3];
	char	*replacement;

	i[0] = 0;
	i[1] = 0;
	while ((*line)[i[0]])
	{
		if ((*line)[i[0]] == '\'' && i[1] == 0)
			i[1] = 1;
		else if ((*line)[i[0]] == '\'' && i[1] == 1)
			i[1] = 0;
		if ((*line)[i[0]] == '$' && i[1] == 0)
		{
			i[2] = extract_rep(&(*line)[i[0] + 1], s->env, &replacement);
			if (replacement)
			{
				(*line) = insert_string((*line), replacement, i[0], i[2] + 2);
				i[0] += ft_strlen(replacement);
			}
			if (replacement)
				free(replacement);
		}
		i[0]++;
	}
}
