
#include "gnl.h"

char	*get_next_line(int fd)
{
	int	i = 0;
	char	character;
	int	rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	char	*line = malloc(100000);

	if (BUFFER_SIZE <= 0)
	{
		free(line);
		return (NULL);
	}
	while (rd > 0)
	{
		line[i] = character;
		i++;
		if (character == '\n')
			break ;
		rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	}
	line[i] = '\0';
	if (rd == -1 || i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
int main(void)
{
    int fd;
    char *str;
    
    fd = open ("test.txt", O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
 		printf("%s", str);
 		free(str);
 		str = get_next_line(fd);
    }
    return (0);
}