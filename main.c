#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>


/*int   main(void)
{
        int             fd;
        char    *line;
        int             i;

        i = 0;
        fd = open("test.txt", O_RDONLY);
        line = get_next_line(fd);
        printf("Line : %s ", line);
        free(line);
        line = get_next_line(fd);
        printf("Line : %s ", line);
        free(line);
        line = get_next_line(fd);
        printf("Line : %s ", line);
        free(line);
        close(fd);
        return (0);
}*/


//test read from file
int     main(void)
{
        int     fd;
        char    *leftover = NULL;
        char    *data;

        fd = open("test.txt", O_RDONLY);
        if (fd == -1)
        {
                printf("error");
                return(1);
        }
        data = read_from_file(fd, leftover);
        if (data == NULL)
        {
                printf("error reading file");
                close(fd);
                return (1);
        }
        printf("data read from file: %s\n", data);
        free(data);
        close(fd);

        return(0);
}
