/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reshuffle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:12:23 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/01/20 01:09:07 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//	insert a string at a position in another string, replacing an amount of characters
char	*insert_string(char *line, char *add, int pos, int skipc)
{
	int		i;
	char	*new;

	i = 0;
	new = calloc(ft_strlen(line) + ft_strlen(add) + 10, sizeof(char));
	while(i < pos)
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
	if (add[0])
		i = pos + skipc;
	while (line[i])
	{
		new[ft_strlen(new)] = line[i];
		i++;
	}
	free(line);
	return(new);
}

int	keylen(char *inp)
{
	int	i;

	i = 0;
	while (inp[i] && (ft_isalnum(inp[i]) || inp[i] == '_'))
	{
		i++;
	}
	return(i);
}

char	*varfinder(char *org, int i, t_shell *s)
{
	char	*value;
	int		slen;
	int     alt;
	char    *res;

	value = NULL;
	alt = 1;
	res = ft_strdup(org);
	if (!ft_strncmp(res+i, "$?", 2))
		value = ft_itoa(g_return);
	if (!ft_strncmp(res+i, "$0", 2))
		value = ft_strdup("minishell");
	// if (ft_strncmp(org, "$$", 2))
	// 	value = ft_itoa(getpid()));
	slen = 2;
	if (!value && keyfinder(&res[i + 1], keylen(&res[i + 1]), s->env) >= 0)
	{
	    alt = 0;
		value = &s->env[keyfinder(&res[i + 1], keylen(&res[i + 1]), s->env)][keylen(&res[i + 1]) + 1];
		slen = keylen(&res[i + 1]) + 1;
	}
	if (value)
		res = insert_string(res, value, i, slen);
	if (alt)
		free (value);
	free(org);
	return (res);
}

char	*inserter(char *org, t_shell *s)
{
	char	qflag;
	int		i;
	char    *res;

	i = 0;
	qflag = 0;
	res = ft_strdup(org);
	while (res[i])
	{
		if (res[i] == '"' && !qflag)
			qflag = '"';
		else if (res[i] == '\'' && !qflag)
			qflag = '\'';
		else if (res[i] == '"' && qflag == '"')
			qflag = 0;
		else if (res[i] == '\'' && qflag == '\'')
			qflag = 0;
		if (res[i] == '$' && res[i + 1] && (ft_isalnum(res[i + 1]) || res[i + 1] == '_'))
		{
			if (qflag != '\'')
			{
				res = varfinder(res, i, s);
				i += keylen(&org[i + 1]);
			}
		}
		i++;
	}
	free (org);
	return (res);
}

/*

skip characters like \ or ; in the input, they may be in the output, see below

$? -> insert value of GlobalPrevReturn
$0 -> name of executable -> "minishell"
$$ -> PID
$  -> \$
*/

// int	main(int argc, char **argv, char **env)
// {
// 	t_shell	s;

// 	if (argc != 1 || argv[1])
// 		return(2);
// 	create_env(env, &s);
// 	// disp_env(&s);

// 	char	*arg = ft_strdup("lal \'$PATH  \"$PATH\" \'  lel");
// 	printf("before	%s\n", arg);
// 	arg = inserter(arg, &s);
// 	printf("after	%s\n", arg);
// 	return (0);
// }
