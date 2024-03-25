#include "get_next_line.h"

char    *join_and_free(char *leftover, char *buffer)
{
        char    *temp;

        temp = ft_strjoin(leftover, buffer);
        free(leftover);
        return (temp);
}

char    *read_from_file(int fd, char *leftover)
{
        char    *buffer;
        int             bytes_read;

        if (!leftover)
                leftover = ft_calloc(1, 1);
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char)); //allocates memory for buffer plus null terminator
        if (!buffer)
                return (NULL);
        bytes_read = 1;
        while (bytes_read > 0)
        {
                bytes_read = read(fd, buffer, BUFFER_SIZE); //read file
                if (bytes_read == -1) //if error
                {
                        free (leftover);
                        free (buffer);
                        return (NULL);
                }
                buffer[bytes_read] = 0; //null terminate
                leftover = join_and_free(leftover, buffer);
                if (ft_strchr(leftover, '\n'))
                        break ;
        }
        free (buffer);
        return (leftover);
}

char    *extract_line(char *leftover)
{
        int             i;
        char    *str;

        i = 0;
        if (!leftover[i])
                return (NULL);
        while (leftover[i] && leftover[i] != '\n')
                i++;
        str = ft_calloc(i + 2, sizeof(char));
        i = 0;
        while (leftover[i] && leftover[i] != '\n')
        {
                str[i] = leftover[i];
                i++;
        }
        if (leftover[i] && leftover[i] == '\n')
                str[i++] = '\n';
        return (str);
}


char    *clean_file(char *leftover)
{
        int             i;
        int             j;
        char    *str;

        i = 0;
        j = 0;
        while (leftover[i] && leftover[i] != '\n')
                i++;
        if (!leftover[i])
        {
                free (leftover);
                return (NULL);
        }
        str = ft_calloc((ft_strlen(leftover) - i + 1), sizeof(*leftover));
        if (!str)
                return (NULL);
        while (leftover[++i])
                str[j++] = leftover[i];
        str[j] = '\0';
        free (leftover);
        return (str);
}

char    *get_next_line(int fd)
{
        char            *output;
        static char     *leftover;

        if (fd < 0 || BUFFER_SIZE <= 0)
                return (NULL);
        leftover = read_from_file(fd, leftover);
        if (!leftover)
                return (NULL);
        output = extract_line(leftover);
        leftover = clean_file(leftover);
        return (output);
}


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




