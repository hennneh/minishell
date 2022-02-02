/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doller.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:20:08 by kchaniot          #+#    #+#             */
/*   Updated: 2022/02/02 17:17:10 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check_if_in_env(char *s, t_shell *sh)
{
	int		i;
	char	*ret;
	t_envar	*en;

	ret = NULL;
	i = 0;
	en = msh_getenv(sh->env, s);
	if (en)
	{
		if (en->value)
			ret = ft_strdup(en->value);
		else
			ret = ft_strdup("");
	}
	return (ret);
}

void	serror(char *s)
{
	printf("%s\n", s);
	exit(1);
}

int		check_var(char *s, char *buf, int *j, t_shell *sh)
{
	int		i;
	int		k;
	char	*ret;
	char	*temp;

	i = 0;
	while (s[i] && (ft_isalpha(s[i]) || s[i] == '_'))
		i++;
	if (i == 0)
		return (1);
	temp = ft_substr(s, 0, i);
	ret = check_if_in_env(temp, sh);
	k = 0;
	if (ret != NULL)
		while (ret[k])
			buf[(*j)++] = ret[k++];
	free(temp);
	free(ret);
	return (i);
}

int		copy_squotes(char *s, char *buf, int *j)
{
	int	i;

	i = 1;
	buf[(*j)++] = '\'';
	while (s[i] && s[i] != '\'')
		buf[(*j)++] = s[i++];
	buf[(*j)++] = s[i++];
	return (i);
}

int		copy_dquotes(char *s, char *buf, int *j, t_shell *sh)
{
	int	i;

	i = 1;
	buf[(*j)++] = '\"';
	while (s[i] && s[i] != '\"')
	{
		while (s[i] != '$' & s[i] != '\"')
			buf[(*j)++] = s[i++];
		while (s[i] == '$' && s[i + 1] == '$')
			buf[(*j)++] = s[i++];
		if (s[i] == '$' && (s[i + 1] == ' ' || s[i + 1] == '?' || s[i + 1] == '\"' || s[i + 1] == '\''))
			buf[(*j)++] = s[i++];
		if (s[i] == '$')
		{
			i += (check_var(&s[i + 1], buf, j, sh));
			i++;
		}
		else
			buf[(*j)++] = s[i++];
	}
	return (i);
}

char	*replace_vars(t_shell *sh)
{
	int	i;
	int	j;
	char	*s;
	char	*buf;

	buf = ft_calloc(1000, sizeof(char));
	i = 0;
	j = 0;
	s = ft_strdup(sh->input);
	while (s[i])
	{
		if (s[i] == '\'')
			i += copy_squotes(&s[i], buf, &j);
		else if (s[i] == '\"')
			i += copy_dquotes(&s[i], buf, &j, sh);
		else if (s[i] == '$')
			i += dollar(&s[i], buf, &j, sh);
		else
			buf[j++] = s[i++];
	}
	free(s);
	sh->input = buf;
	return (buf);
}

int		dollar(char *s, char *buf, int *j, t_shell *sh)
{
	int i;

	i = 0;
	while (s[i] && s[i] == '$' && s[i + 1] == '$')
		buf[(*j)++] = s[i++];
	if (s[i] == '$' && (s[i + 1] == ' ' || s[i + 1] == '?' || \
	s[i + 1] == '\'' || s[i + 1] == '\"' || s[i + 1] == '\0'))
	{
		buf[(*j)++] = s[i++];
		return (i);
	}
	if (s[i] == '$')
		i += (check_var(&s[i + 1], buf, j, sh));
	i++;
	return (i);
}

int		check_quotes(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i])
				i++;
			if (!s[i])
				return (1);
		}
		if (s[i] == '\"')
		{
			i++;
			while (s[i] != '\"' && s[i])
				i++;
			if (!s[i])
				return (1);
		}
		i++;
	}
	return (0);
}