#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "get_next_line.h"
# include "mylib.h"

/* mandatory */
# include <stdio.h>
/* printf */
# include <string.h>
/* strerror */
# include <stdlib.h>
/* malloc, free, exit, getenv */
# include <unistd.h>
/* write, read, close, fork, getcwd, chdir, execve */
/* dup, dup2, pipe, isatty, ttyname, ttyslot */
# include <fcntl.h>
/* open */
# include <sys/wait.h>
/* wait, waitpid, wait3, wait4 */
# include <signal.h>
/* signal, kill */
# include <sys/stat.h>
/* stat, lstat, fstat */
# include <dirent.h>
/* opendir, readdir, closedir */
# include <sys/errno.h>
/* errno */
# include <sys/ioctl.h>
/* ioctl */
# include <termios.h>
/* tcsetattr, tcgetattr, tgetent */
# include <term.h>
/* tgetent, tgetflag, tgetnum,  tgetstr, tgoto, tputs */
# include <signal.h>
/* signals */
# define MINISHELL "MINISHELL $> "

typedef struct s_cmd
{
	char	*command;
	char	**argv;
}	t_cmd;

char	*command_input(char *envp[]);
t_cmd	*command_parse(char *line);
void	free_cmd(t_cmd **cmd);
int		ms_issep(char c)
int		ms_lexer(char *line, t_list **lex_cmd);
void	ms_echo(char **argv);

#endif /* MINISHELL_H */
