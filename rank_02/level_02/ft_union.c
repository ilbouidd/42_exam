#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    int i = 0;
    int look[256] = {};

    if (ac == 3)
    {
        while (av[1][i])
        {
            look[(int)av[1][i]] = 1;
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            look[(int)av[2][i]] = 1;
            i++;
        }
        i = 0;
        while (av[1][i])
        {
            if (look[(int)av[1][i]] == 1)
            {
                ft_putchar(av[1][i]);
                look[(int)av[1][i]] = 0;
            }
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            if (look[(int)av[2][i]] == 1)
            {
                ft_putchar(av[2][i]);
                look[(int)av[2][i]] = 0;
            }
            i++;
        }
    }
    ft_putchar('\n');
}