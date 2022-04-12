/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:01:07 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:01:09 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 * DEFINES
 */

# define MAX_PATH 1024

/*
**	LIBRARY
*/

# include "../lft/libft.h"

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
# include <errno.h>
/*
** GLOBAL VARIABLE
*/

char	g_errnum;

/*
** MACROS
*/
# ifndef MAX_PATH
#  define MAX_PATH 1000
# endif
# define MAX_DIR 1000
# define PROMPT "\e[32mminishell \e[31mv1.0\e[0m $ "
# define PIPE '|'
# define S_Q '\''
# define D_Q '\"'

/*
**	STRUCTS
*/

/**
 * Sequence struct
 * @param seq string befor being split
 * @param split string array containing the splitted sequence
 * @param path_cmd string (for bash) exe path and cmd
 * @param cmd_arg argumants (for bash) for the cmd
 * @param fd int array contains input and output fd
 * @param wht_cmd [int] 0 if shell cmd, + if ours
 * @param nbr_arg [int] number of argument
*/
typedef struct s_seq
{
	char	*seq;
	char	**split;
	char	*path_cmd;
	char	**cmd_args;
	int		fd[2];
	int		wht_cmd;
	int		nbr_arg;
}	t_seq;

/**
 * Main Struct
 * @param env linked t_list for enviroment
 * @param seq Seq Struct array 
 * @param n_cmds [int] nbr of pipe splits needed
 * @param input string containing the whole input from the user
*/
typedef struct s_shell
{
	t_list	*env;
	t_seq	**seq;
	int		n_cmds;
	char	*input;
}	t_shell;

/*
**Environment Content Struct
@param key variable name
@param value variable content
*/
typedef struct s_cont
{
	char	*key;
	char	*value;
}	t_cont;

/*
 * FUNCTIONS
*/

//	environment

t_cont	*envar(char *p_var);
void	delvar(t_list *elem);
t_list	*create_env(char **p_env);
char	**env_copy(t_list *p_env);
void	del_list(char **list);
t_list	*de_key(t_list *env, char *line);
t_list	*finder(t_list *env, char *key);
int		keyer(char *input);

//	signals

void	init_sig(void);
int		is_running(pid_t pid);
void	sig_handler_child(int signum);
void	sigint_handler(int signum);

// EXTRACT

int		extract_cmd(t_shell *sh);

//	PARSE
int		ft_white(char c);
int		is_whspace(char *s, int dir);
char	*trm_whtsp(char *s, int dir);
int		pipe_quote(int pos, char c, char *in);
int		pipe_split(t_shell *shell, char *in, int pos1, int pos2);
int		is_split(char c);
int		arg_split(char *s, t_seq *seq, int pos1, int i);
char	*rmv_quotes(char *s, int f);
char	*ft_get_path( char **cmd, char **path);
int		init_fd(t_seq *seq, char **sp);
char	**ft_path(t_shell *s);
int		parse(t_shell *sh, int i);

// Launch

int		launch_cmd(t_shell *sh);
void	ft_pipe(t_shell *sh, t_seq *seq);
void	ft_pipe_last(t_shell *sh, t_seq *seq, int s_fd[2]);
void	ms_exec_builtins(t_shell *s, t_seq *q, pid_t pid);

// Clean

void	clean_seq(t_shell *sh);
void	ms_error(int error, char *sub, char *msg, int p);
int		close_fd(void);

/*
**	MAIN
*/
void	interpret(t_shell *s, char **line);
void	ms_echo(char **array, pid_t pid);
void	cd(char **array, t_shell *shell, pid_t pid);
void	pwd(pid_t pid);
void	ms_env(t_shell *s, t_seq *q, pid_t pid);
void	ms_export(t_shell *s, t_seq *q, pid_t pid, int i);
void	ms_unset(t_shell *s, t_seq *q, pid_t pid, int i);

int		shell(char **env);

int		ms_exit(t_shell *s, t_seq *q, pid_t pid);

#endif
