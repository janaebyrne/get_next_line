#include "get_next_line.h"


char    *read_from_file(int fd, char *leftover)
{       
        char    *buffer;
	size_t	bytes_read;

        bytes_read = 1;
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
        if (buffer == NULL)
                return (NULL);
        while (bytes_read != 0 && indexfind(leftover, '\n') == -1)
	{
        	bytes_read = read(fd, buffer, BUFFER_SIZE);
        	if (bytes_read <= 0)
		{
			free(buffer);
			free(leftover);
			buffer = NULL;
               		 return (0);
		}
		buffer[bytes_read] = '\0';
		leftover = ft_strjoin(leftover, buffer);
		if (!leftover)
			leftover = ft_strdup(buffer);
	}
	free(buffer);
	buffer = NULL;
        return(leftover);
}


char	*find_line(char *leftover)
{
	char	*line;
	int	position;
	int i;

	i = 0;
	position = indexfind(leftover, '\n');
	if (position != -1)
		line = (char *)malloc(sizeof(char) * (position + 2));
	else
		line = (char *)malloc(sizeof(char) * (ft_strlen(leftover) + 1));
	if (!line)
		return (0);
	while (leftover && leftover[i] != '\n')
		{
			line[i] = leftover[i];
			i++;
		}
	if (leftover[i] == '\n')
		{
			line[i] = leftover[i];
			i++;
		}
	line[i] = '\0';
	return(line);
}

char	*findleftover(char *leftover)
{
	char	*string;
	int	position;
	int	i;

	position = indexfind(leftover, '\n');
	i = 0;
	if (position != -1)
		string = (char *)malloc(sizeof(char) * (ft_strlen(leftover) - position));
	else 
		string = (char *)malloc(sizeof(char) * 1);
	if (!string)
		return (0);
	while (position != -1)
		{
			string[i] = leftover[position + 1 + i];
			i++;
		}
	string[i] = '\0';
	free (leftover);
	return (string);
}

char    *get_next_line(int fd)
{
        static char    *leftover;
        char    *line;

        if (BUFFER_SIZE <= 0 || fd < 0)
                return (0);

        leftover = read_from_file(fd, leftover);
        if (!leftover)
                return(0);
        line = find_line(leftover);
        if (!leftover || ft_strlen(line) == 0)
        {
                free(leftover);
                free(line);
                leftover = NULL;
                return(NULL);
        }
        leftover = findleftover(leftover);
        return (line);
}
