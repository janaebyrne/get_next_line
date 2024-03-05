#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int     indexfind(char *str, char c);
char *ft_strjoin(char *s1, char *s2);
int     ft_strlen(const char *str);
char    *ft_strdup(const char *str);
char    *read_from_file(int fd, char *leftover);

#endif


