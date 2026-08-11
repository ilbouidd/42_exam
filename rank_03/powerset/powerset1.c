#include<stdio.h>
#include<stdlib.h>

int main (int ac, char **av)
{
    int n = ac - 2;
    int res = atoi(av[1]);

    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if((mask >> i) & 1)
                sum += atoi(av[2 + i]);
        }
    }
}