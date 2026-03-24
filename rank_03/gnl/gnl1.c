#include "gnl.h"

char *get_next_line(int fd)
{
    int i = 0;
    char *line = malloc(100000);
    char characters;
    int rd = read(fd, &characters, BUFFER_SIZE - BUFFER_SIZE + 1);

    if (rd < 0)
    {
        free(line);
        return (NULL);
    }
    while (rd > 0)
    {
        line[i] = characters;
        i++;
        if (characters = '\n')
            break;
        rd = read(fd, &characters, BUFFER_SIZE - BUFFER_SIZE + 1);
    }
    line[i] = '\0';
    if (rd == -1 || i == 0)
    {
        free(line);
        return (NULL);
    }
    return (line);
}

int main(int ac, char **av)
{
    int fd = open("test.txt", O_RDONLY);
    char *str = get_next_line(fd);
    
    while (str)
    {
        printf("%s", str);
        str = get_next_line(fd);
    }
    return (0);
}