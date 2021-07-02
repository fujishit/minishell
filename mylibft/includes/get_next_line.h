/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:55:05 by mfujishi          #+#    #+#             */
/*   Updated: 2021/04/14 09:05:55 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 256

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		gnl_read(int fd, char **save);
int		gnl_save(char **save, char **line);
int		free_return(void *buf, int ret);

char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);

#endif
