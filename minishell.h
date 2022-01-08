/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:22:46 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/07 17:24:16 by vheymans         ###   ########.fr       */
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
**	STRUCTS
*/

typedef struct s_cmd	t_cmd;

/*
** env == enviroment; his == history; n_cmds == # of cmds;
** pwd = print(present)_working_dir; ** cmds == holds all the cmds;
** input = output from readline;
*/

typedef struct s_shell
{
	char	**env;
	t_lst	*his;
	int		n_cmds;
	char	*pwd;
	t_cmd	*cmds;
	char	*input;
}	t_shell;

/*
**fd == contains input and output fd; append_flag == if it needs to be appended;
**path_cmd == exe path and cmd; cmd_arg == argumants for the cmd;
*/

typedef struct s_cmd
{
	int		fd[2];
	int		append_flag;
	char	*path_cmd;
	char	**cmd_args;
}	t_cmd;

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
