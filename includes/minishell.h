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

# define NO_REDIRECT 0 //
# define REDIRECT_IN 11 // <
# define HERE_DOCUMENT 12 // <<
# define REDIRECT_OUT 21 // >
# define ADD_REDIRECT_OUT 22 // >>
# define PIPE 31 // |

typedef struct s_meta	t_meta;

typedef struct s_cmd
{
	int		argc;
	char	**argv;
	t_meta	*nextmeta;
}	t_cmd;

typedef struct s_meta
{
	int		meta;
	t_cmd	*nextcmd;
}	t_meta;

char	*command_input(char *envp[]);
t_cmd	*command_parse(char *line);
void	free_cmd(t_cmd *cmd);
void	free_list(t_list *lex);
int		issep(char c);
int		lexer(char *line, t_list **lex_cmd);
int		parser(t_list *lex, t_cmd **cmd);
int		echo(int argc, char **argv);
int		pwd();
int		env(char *envp[]);

void	ft_exit(t_cmd *cmd);

#endif /* MINISHELL_H */
