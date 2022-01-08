/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:22:46 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/08 18:35:24 by kchaniot         ###   ########.fr       */
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
**fd == contains input and output fd; append_flag == if it needs to be appended;
**path_cmd == exe path and cmd; cmd_arg == argumants for the cmd;
*/

typedef struct s_seq
{
	int		fd[2];
	int		append_flag;
	int		create_flag;
	int		here_doc_flag;
	int		input_red_flag;
	t_cmd	cmd;
}	t_seq;

typedef struct s_cmd
{
	char	*path_cmd;
	char	**cmd_args;
}				t_cmd;

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

char	**get_path(char **path);

#endif
