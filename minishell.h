/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:22:46 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/14 15:24:19 by vheymans         ###   ########.fr       */
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
	int		fd[2];
	int		wht_cmd;
	int		append_flag;
	int		create_flag;
	int		here_doc_flag;
	int		input_red_flag;
	t_cmd	*cmd;
}	t_seq;

/*
**	FUNCTIONS
*/

/*
**	MAIN
*/

int		shell(char **env);

/*
**	UTILIES
*/

char	**ft_path(char **env);
char	*ft_get_path(char **path, char **cmd);
int		cmd_new(t_cmd *new, char *argv, char **path);
void	free_cmd(t_cmd *elem, int nelem);
char	*find_limitor(char *s);

/*
**TESTING (to be removed)
*/

int		shell_t(char **env);

#endif
