#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	int	i = 0;
	char *s2;

	while (s1[i])
		i++;
	s2 = malloc(sizeof(char) * i + 1);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*get_next_line(int fd)
{
	int	i = 0;
	static char buffer[BUFFER_SIZE];
	char line[10000];
	static int r = 0;
	static int buffer_pos = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= r)
		{
			r = read (fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (r == 0)
				break;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

int main()
{
	int fd = open ("subject.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
