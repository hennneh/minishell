/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:45:37 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/01/19 20:12:17 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
/*
	Overview in this File:
		create the execution of the command "export"
	--export--
		change / create an environmental variable, depending on its prevoius existance
			if the <key> is not entirely alphaNumreic + '_' (& s[0] != num), the input "is not a valid identifier" --Error
		if it already exists, (the <key> matches a <key> in the env) the <value> is replaced
			else an new variable is created (in bash at a seemingly random position, here at the end)
		if there is no input at all OR the first input is '#'
			the output shall be a list of all the environmental variables in
			Alphabetical order, sorted by ascii
		if there is a '-' then the next char will be interpreted as a flag, "invalid option"
		if '$?' is in the key, it is interpreted as the $? value
		strange behaviour around the '$' character
*/

void	sort_list(char ***plist)
{
	int		i[2];
	char	*tmp;
	char	**list;

	list = *plist;
	i[0] = 0;
	i[1] = 0;
	while (i[0] < outerlen(list) && list[i[0]] && list[i[0] + 1])
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

void	alph_env(t_shell *s) // still need to >\< each meaningful char
{
	char	**list;
	char	tmp[2];
	int		o;
	int		i;

	list = ft_calloc(outerlen(s->env) + 1, sizeof(char *));
	i = 0;
	while (i < outerlen(s->env))
	{
		list[i] = ft_strjoin(s->env[i], "\0\0");
		if (ft_strchr(list[i], '='))
		{
			o = (int)(ft_strchr(list[i], '=') - list[i]) + 1;
			tmp[1] = '"';
			while (list[i][o - 1])
			{
				tmp[0] = list[i][o];
				list[i][o] = tmp[1];
				tmp[1] = tmp[0];
				o++;
			}
			list[i][ft_strlen(list[i])] = '"';
		}
		i++;
	}
	sort_list(&list);
	i = 0;
	while (list[i])
	{
		printf("declare -x %s\n", list[i]);
		i++;
	}
}

int	exportsingle(t_shell *s, char *input)
{
	int		keylen;
	int		nnew;
	char	**new;
	int		i;

	keylen = ft_strlen(input);
	if (ft_strchr(input, '='))
		keylen = (int)(ft_strchr(input, '=') - input);
	nnew = 1;
	if	(keyfinder(input, keylen, s->env) >= 0)
		nnew = 0;
	new = ft_calloc(outerlen(s->env) + 1 + nnew, sizeof(char *));
	i = 0;
	while (s->env[i])
	{
		new[i] = s->env[i];
		if (i == keyfinder(input, keylen, s->env) && !nnew)
		{
			free(new[i]);
			new[i] = ft_strdup(input);
		}
		i++;
	}
	if (nnew)
		new[i] = ft_strdup(input);
	free(s->env);
	s->env = new;
	return (0);
}

int	ms_export(t_seq *q, t_shell *s)
{
	int	i;

	if (!q || !s)
		return 1;
	if (!q->cmd.cmd_args[0] || q->cmd.cmd_args[0][0] == '#')
	{
		alph_env(s);
		return (0);
	}
	i = 0;
	while (q->cmd.cmd_args[i])
	{
		if (key_error(q->cmd.cmd_args[i]) && q->cmd.cmd_args[i][0] != '#')
			printf("bash: export: `%s'not a valid identifier\n", q->cmd.cmd_args[i]);
		else if (q->cmd.cmd_args[i][0] != '#')
			exportsingle(s, q->cmd.cmd_args[i]);
		i++;
	}
	return 0;
}

// int	main(int argc, char **argv, char **env)
// {
// 	t_shell	s;

// 	if (argc != 1 || argv[1])
// 		return(2);
// 	create_env(env, &s);
// 	// disp_env(&s);

// 	t_seq	*q = ft_calloc(1, sizeof(t_seq));

// 	//	test the functionality of export
// 	q->cmd.cmd_args = ft_split("lal meme meh", ' ');
// 	ms_export(q, &s);
// 	free(q->cmd.cmd_args);
// 	q->cmd.cmd_args = ft_split("#", ' ');
// 	ms_export(q, &s);
	
// 	free(q);
// 	return(0);
// }
