#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i] && i != n - 1)
        i++;
    return (s1[i] - s2[i]);
}

int main (int ac, char ** av)
{
    if (ac == 2)
    {
        int i = 0;
        int j = 0;
        char c;
        int len = strlen(av[1]);
        char str[70000];
        int r = read(0, &c, 1);

        if (r <= 0)
        {
            perror("Error: ");
            return (1);
        }
        while (r)
        {
            str[i] = c;
            i++;
            r = read(0, &c, 1);
        }
        str[i] = '\0';
        i = 0;
        while (str[i])
        {
            if (ft_strncmp(av[1], &str[i], len) == 0)
            {
                j = 0;
                while (j != len)
                {
                    write(1 , "*", 1);
                    i++;
                    j++;
                }
            }
            else
                write(1, &str[i++], 1);
        }
    }
    else 
        return (1);
}