#include "get_next_line.h"

void    ft_bzero(void *str, size_t n)
{
        char    *p;
        size_t  i;

        p = (char *)str;
        i = 0;
        while (i < n)
        {
                p[i] = '\0';
                p++;
        }
}

int     ft_strlen(const char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
                i++;
        return (i);
}

void    *ft_calloc(size_t num_elements, size_t element_size)
{
        size_t                  total_size;
        unsigned char   *ptr;

        total_size = num_elements * element_size;
        ptr = malloc(total_size);
        if (!ptr)
                return (NULL);
        ft_bzero(ptr, total_size);
        return (ptr);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
        char    *joined;
        size_t  totallength;
        size_t  i;
        size_t  j;

        totallength = ft_strlen(s1) + ft_strlen(s2);
        i = 0;
        j = 0;
        joined = malloc(sizeof(char) * (totallength + 1));
        if (!joined || !s1 ||!s2)
                return (NULL);
        while (s1[i] != 0)
        {
                joined[i] = s1[i];
                i++;
        }
        j = 0;
        while (s2[j] != 0)
        {
                joined[i] = s2[j];
                i++;
                j++;
        }
        joined[i + j] = 0;
        return (joined);
}

char    *ft_strchr(const char *string, int character )
{
        char    *str;

        str = (char *)string;
        while (*str != character && *str != 0)
                str++;
        if (*str == character)
                return (str);
        else
                return (NULL);
}




