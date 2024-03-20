#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	ft_bzero(void *str, size_t n);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t num_elements, size_t element_size);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *string, int character);

#endif

