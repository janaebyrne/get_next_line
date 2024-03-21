#include "get_next_line.h"

/*int   isbinary(char *leftover)
{
        size_t  i;

        if (!leftover)
                return 0;
        i = 0;
        while (leftover[i] && leftover[i] != '\n')
        {
                if (leftover[i] == '\0' || leftover[i] < 32 || leftover[i] > 126)
                {
                        if (leftover[i] == '\0' && leftover[i + 1] == '\0')
                                break ;
                        else
                                return (1);
                }
                i++;
        }
        return (0);
}*/


// reads the file and returns the text
char    *read_from_file(int fd, char *leftover)
{
        char    *buffer;
        int             bytes_read;

        if (!leftover)
                leftover = ft_calloc(1, 1);
        buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
        if (!buffer)
                return (NULL);
        bytes_read = 1;
        while (bytes_read > 0)
        {
                bytes_read = read(fd, buffer, BUFFER_SIZE);
                if (bytes_read == -1)
                {
                        free(buffer);
                        return (NULL);
                }
                buffer[bytes_read] = '\0';
                leftover = ft_strjoin(leftover, buffer);
                if (ft_strchr(buffer, '\n'))
                        break ;
        }
        free(buffer);
        return (leftover);
}



// extracts the line to return
char    *extract_line(char *leftover)
{
        char    *line;
        int             i;

        i = 0;
        if (!leftover[i])
                return (NULL);
        while (leftover[i] && leftover[i] != '\n')
                i++;
        line = ft_calloc((i + 2), sizeof(char));
        if (!line)
                return (NULL);
        i = 0;
        while (leftover[i] && leftover[i] != '\n')
        {
                line[i] = leftover[i];
                i++;
        }
        if (leftover[i] && leftover[i] == '\n')
        {
                line[i++] = '\n';
        }
        return (line);
}
//deletes the line found to give the leftover

char    *findnewstring(char *leftover)
{
        int             i;
        int             j;
        char    *newstring;

        i = 0;
        while (leftover[i] && leftover[i] != '\n')
                i++;
        if (!leftover[i])
        {
                free(leftover);
                return (NULL);
        }
        newstring = ft_calloc((ft_strlen(leftover) - i + 1), sizeof(char));
        i++;
        j = 0;
        while (leftover[i])
                newstring[j++] = leftover[i++];
        free(leftover);
        return (newstring);
}



char    *get_next_line(int fd)
{
        char    *line;
        char    *leftover;

        leftover = NULL;
        if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
                return (NULL);
        leftover = read_from_file(fd, leftover);
        if (!leftover)
                return (NULL);
        line = extract_line(leftover);
        leftover = findnewstring(leftover);
        return (line);
}
// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("test.txt", O_RDONLY);
//     if (fd < 0) {
//         perror("Error opening file");
//         return (1);
//     }
//     line = get_next_line(fd);
//      printf("line is:%s", line);
//      line = get_next_line(fd);
//      printf("nextlineis:%s", line);
//      line = get_next_line(fd);
//      printf("nextlineis%s", line);
//     free(line);
//     close(fd);
//     return (0);
// }




