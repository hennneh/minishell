/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:59:36 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/01/18 14:12:41 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../../minishell.h"

//	gcc export.c env.c unset.c utils.c ../../minishell.h ../../libft/libft.a -g

//	FOREWORD: as of the current state of this brach, not all cases in the functions
//		env, unset and export are covered and are still being worked on.

//	create a copy of the maingiven environmemt; store it in the t_shell
int	create_env(char **sysenv, t_shell *s);
//	return the number of char* in a char**
size_t	outerlen(char **list);
//	check if a <key> (char*) is found in a char** and if return its position (else - 1)
int	keyfinder(char *key, int keylen, char **list);
//	check that the <key> isalphanumerical
int	key_error(char *input);

//	display all environmental variables which have values
void	ms_env(t_seq *q, t_shell *s);
//	create / replace environmental variables
int	ms_export(t_seq *q, t_shell *s);
//	remove environmental variables
void	ms_unset(t_seq *q, t_shell *s);
//	a function to extract the value of an environmental variable
char	*getenv(char *key, t_shell *s);

#endif