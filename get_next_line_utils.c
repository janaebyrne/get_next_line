#include "get_next_line.h"

void	ft_bzero(void *str, size_t n)
{
	char	*p;

	p = (char *)str;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t			total_size;
	unsigned char	*ptr;

	if (num_elements > 0 && SIZE_MAX / num_elements < element_size)
	{
		return (NULL);
	}
	total_size = num_elements * element_size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	joined = malloc(sizeof(char) * (len1 + len2 + 1));
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

char	*ft_strchr(const char *string, int character )
{
	char	*str;

	str = (char *)string;
	while (*str != character && *str != 0)
		str++;
	if (*str == character)
		return (str);
	else
		return (NULL);
}
// char	*ft_strrchr(const char *str, int character)
// {
// 	int		i;
// 	char	c;

// 	c = (char)character;
// 	i = ft_strlen(str) - 1;
// 	while (str[i] != c && (i >= 0))
// 		i--;
// 	if (i >= 0)
// 		return ((char *)&str[i]);
// 	else
// 		return (NULL);
// }

