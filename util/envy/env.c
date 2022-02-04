/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:53:05 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/02/02 17:09:28 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	Overview in this File:
		create the execution of the commands "env"
	--env--
		display the environmental variables, including those changes by "export" and "unset"
		only display if a <key>=<value> structure is apparent

		Arguments or Flags should not be handeled

		we now use lists to store key and value seperately and to have flags on whether it is to be printed or only stored etc
				-> edge case of unset && cd || echo

		normal print status is (export)			1
		unsetting PWD or HOME switches print to	0
		cd (if currently 0) sets HOME or PWD to	2		so that it doesn't show up in env, but can be used as a Var
*/

void	delvar(void *rmv);

//	return the number of lines in a list
int	outerlen(char **list)
{
	int i;

	i = 0;
	while(list && list[i])
	{
		i++;
	}
	return (i);
}

//	insert a string at a position in another string, replacing the <key>
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

t_list	*new_envar(char *input, int flag)
{
	t_envar	*content;
	t_list	*new;

	content = malloc(sizeof(t_envar));
	if (ft_strchr(input, '='))
	{
		content->key = ft_substr(input, 0, ft_strchr(input, '=') - input);
		content->value = ft_strdup(ft_strchr(input, '=') + 1);
		content->print = 1;
	}
	else
	{
		content->key = ft_substr(input, 0, ft_strlen(input));
		content->value = NULL;
		content->print = 0;
	}
	if (flag > 0)
		content->print = flag;
	new = ft_lstnew(content);
	return (new);
}

t_list	*copy_env(char **env)
{
	int		i;
	t_list	*my_env;
	t_list	*next;

	i = 0;
	my_env = NULL;
	while (env[i])
	{
		next = new_envar(env[i], -1);
		if (my_env)
			ft_lstadd_back(&my_env, next);
		else
			my_env = next;
		i++;
	}
	return (my_env);
}

int	display_env(t_list	*env, char dev)
{
	t_list	*temp;
	t_envar	*c;

	temp = env;
	while(temp)
	{
		c = (t_envar *)temp->content;
		if ((dev == 'p' || dev == 'a') && c->value && c->print == 1)
			printf("%s=%s\n", c->key, c->value);
		else if (dev == 'a' && c->print != 1)
			printf("HIDDEN	%s=%s\n", c->key, c->value);
		temp = temp->next;
	}
	return (0);
}


t_envar	*msh_getenv(t_list *env, char *key)
{
	t_list	*tmp;
	int		diff;

	tmp = env;
	while(tmp)
	{
		diff = ft_strncmp(key, ((t_envar *)tmp->content)->key, ft_strlen(key));
		if (diff == 61 || diff == 0)
			return ((t_envar *)(tmp->content));
		tmp = tmp->next;
	}
	return (NULL);
}


void	ms_env(t_seq *q, t_shell *s)
{
	display_env(s->env, 'p');
	(void)q;
}

//#################################

//export

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

void	disp_env(t_list *org)
{
	t_list	*tmp;
	char	**cpy;
	int		i;

	i = 0;
	tmp = org;
	while(tmp)
	{
		i++;
		tmp = tmp->next;
	}
	cpy = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	tmp = org;
	while(tmp)
	{
		i++;
		cpy[i] = ft_calloc(ft_strlen(((t_envar *)(tmp->content))->key) + ft_strlen(((t_envar *)(tmp->content))->value) + 2, sizeof(char));
		ft_strlcpy(cpy[i], ((t_envar *)(tmp->content))->key, ft_strlen(((t_envar *)(tmp->content))->key));
		cpy[i][ft_strlen(cpy[i])] = '=';
		ft_strlcpy(ft_strchr(cpy[i], '='), ((t_envar *)(tmp->content))->value, ft_strlen(((t_envar *)(tmp->content))->value));
		tmp = tmp->next;
	}
}

int	key_error(char *input)
{
	int	i;

	i = 0;
	if (!ft_isalpha(input[0]) && input[i] != '_')
		return (1);
	while (input[i] && input[i] != '=')
	{
		if (!ft_isalnum(input[i]) && input[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	back_out(char ***env)
{
	int		i;
	int		l;
	char	**lst;

	lst = *env;
	l = 0;
	while (lst[l])
	{
		i = 0;
		while (lst[l][i])
		{
			if (lst[l][i] == '$')
			{
				lst[l] = insert_string(lst[l], "\\$", i, 1);
				i++;
			}
			i++;
		}
		l++;
	}
}

int	disp_sorted(t_list *env)
{
	char	**cpy;
	int		i;

	cpy = re_envent(env);
	back_out(&cpy);
	sort_list(&cpy);
	i = 0;
	while (cpy[i])
	{
		printf("declare -x %s\n", cpy[i]);
		i++;
	}
	free_dbchar(cpy);
	return (0);
}

int	msh_export(t_seq *q, t_shell *s)
{
	int		i;
	t_envar	*tmp;
	t_list	*rep;

	if (!q->cmd_args[0] || q->cmd_args[0][0] == '#')
	{
		disp_sorted(s->env);
		return (0);
	}
	i = 0;
	while (q->cmd_args[i])
	{
		if (key_error(q->cmd_args[i]))
			printf("bash: export: `%s'not a valid identifier\n", q->cmd_args[i]);
		else
		{
			rep = new_envar(q->cmd_args[i], -1);
			tmp = msh_getenv(s->env, ((t_envar *)rep->content)->key);
			if (tmp && ((t_envar *)rep->content)->value)
			{
				if (tmp->value)
					free (tmp->value);
				tmp->value = ft_strdup(((t_envar *)rep->content)->value);
				delvar(rep);
			}
			else
				ft_lstadd_back(&s->env, rep);
		}
		i++;
	}
	return (0);
}

/////////////////////////////////////////////////////////////////////////////////////


void	delvar(void *rmv)
{
	t_envar	*c;

	c = ((t_list *)rmv)->content;
	if (c->key)
		free (c->key);
	if (c->value)
		free (c->value);
}

int	create_env(char **env, t_shell *s)
{
	s->env = copy_env(env);
	return (0);
}
// unset SECURITYSESSIONID LaunchInstanceID COMMAND_MODE SHELL LOGNAME TERM _ DISPLAY __CF_USER_TEXT_ENCODING XPC_SERVICE_NAME XPC_FLAGS SSH_AUTH_SOCK SHLVL TERM_PROGRAM TERM_PROGRAM_VERSION LANG COLORTERM VSCODE_GIT_IPC_HANDLE GIT_ASKPASS VSCODE_GIT_ASKPASS_NODE VSCODE_GIT_ASKPASS_MAIN
// int	main(int argc, char **argv, char **env)
// {
// 	t_shell	s;

// 	if (argc != 1 || argv[1])
// 		return(2);
// 	create_env(env, &s);

// 	t_seq	*q = ft_calloc(1, sizeof(t_seq));

// 	//	test the functionality of env
// 	q->cmd_args = ft_split("lal=CHANGEME me", ' ');
// 	msh_export(q, &s);
// 	display_env(s.env, 'a');
// 	write (1, "\n\n\n", 3);
// 	free(q->cmd_args);
// 	q->cmd_args = ft_split("lal=heh _lel 0fef=lel edge=$$$$$ fef\"$?\"0=fe", ' ');
// 	msh_export(q, &s);
// 	for (int i = 0; q->cmd_args[i]; i++)
// 		printf("exporting %s\n", q->cmd_args[i]);
// 	write (1, "\n", 1);
// 	display_env(s.env, 'a');
// 	write (1, "\n\n\n", 3);
// 	free(q->cmd_args);
// 	q->cmd_args = ft_split("", ' ');
// 	msh_export(q, &s);
// 	if (q)
// 		free(q);
// 	//ft_lstclear(&s.env, delvar);
// 	return(0);
// }