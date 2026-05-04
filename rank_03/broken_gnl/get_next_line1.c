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
	
}

int	main()
{
	char *s1 = "ilyass";

	printf("%s\n", ft_strdup(s1));
}
