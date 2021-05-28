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

#endif /* MINISHELL_H */
