/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:22:46 by vheymans          #+#    #+#             */
/*   Updated: 2022/02/01 14:23:44 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**	LIBRARY
*/

# include "libft/libft.h"

/*
**	INCLUDES
*/

# include <stdio.h> // readline, printf
# include <stdlib.h> // malloc, free, exit, getenv, 
# include <fcntl.h> // open
# include <unistd.h> // access, unlink, close, read, write, pipe, dup, dup2,
// execve, fork, getcwd, chdir, stat, lstat, fstat, isatty, ttyname, ttyslot,
// ioctl
# include <sys/wait.h> // waitpid, wait, wait3, wait4
# include <signal.h> // signal, sigaction, kill
# include <sys/types.h> // opendir, closedir
# include <dirent.h> // readdir
# include <stdio.h> // perror
# include <string.h> // strerror
# include <termios.h> // tcsetattr, tcgetattr
# include <curses.h> // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <readline/readline.h>
# include <readline/history.h>

/*
** MACROS
*/

# define PIPE '|'

/*
**	STRUCTS
*/

typedef struct s_seq	t_seq;

/*
** env == enviroment; his == history; n_cmds == # of cmds;
** pwd = print(present)_working_dir; ** seq(uence) == holds cmds/files;
** input = output from readline;
*/

typedef struct s_shell
{
	char	**env;
	t_list	*his;
	int		n_cmds;
	char	*pwd;
	t_seq	**seq;
	char	*input;
}	t_shell;

/*
**path_cmd == exe path and cmd; cmd_arg == argumants for the cmd;
*/

typedef struct s_cmd
{
	char	*path_cmd;
	char	**cmd_args;
}	t_cmd;

/*
**seq == line after being devided by pipes; fd == contains input and output fd;
**append_flag == if it needs to be appended; wht_cmd == 0 if shell cmd, + if ours

*/

typedef struct s_seq
{
	char	*seq;
	char	**split;
	int		fd[2];
	int		wht_cmd;
	int		append_flag;
	int		create_flag;
	int		here_doc_flag;
	int		input_red_flag;
	t_cmd	cmd;
}	t_seq;

/*
**	FUNCTIONS
*/

/*
	Environment
*/

//	create a copy of the maingiven environmemt; store it in the t_shell
int	create_env(char **sysenv, t_shell *s);
//	return the number of char* in a char**
int	outerlen(char **list);
//	check if a <key> (char*) is found in a char** and if return its position (else - 1)
int	keyfinder(char *key, int keylen, char **list);
//	check that the <key> isalphanumerical
int	key_error(char *input);

//	display all environmental variables which have values
void	ms_env(t_seq *q, t_shell *s);
//	create / replace environmental variables
int		ms_export(t_seq *q, t_shell *s);
//	remove environmental variables
int		ms_unset(t_seq *q, t_shell *s);
//	a function to extract the value of an environmental variable
char	*ms_getenv(char *key, t_shell *s);

/*
**	MAIN
*/

int		shell(char **env);

/*
**	UTILIES
*/

char	**ft_path(char **env);
char	*ft_get_path(char **path, char **cmd);
int		cmd_new(t_cmd *new, t_seq *s, char **path);
void	free_cmd(t_cmd *elem, int nelem);
char	*find_limitor(char *s);
int		ft_add_slash(char **array);
int		init_seq(t_seq *seq, char **env);
int		pipe_split(t_shell *shell, char *in);
int		is_whspace(char *s, int dir);
int		quote_check(int pos, char c, char *in);
int		cmd_split(char *s, t_seq *seq);

/*
**TESTING (to be removed)
*/

int		shell_t(char **env);

#endif
