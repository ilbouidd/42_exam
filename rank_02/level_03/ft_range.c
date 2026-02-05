#include <stdio.h>
#include <stdlib.h>


int *ft_range(int start, int end)
{
    int *range;
    int i = 0;
    int len;

    if (start > end)
        return NULL;

    len = end - start + 1;

    range = malloc(sizeof(int) * len);
    if (!range)
        return NULL;
    while (i < len)
    {
        range[i] = start + i;
        i++;
    }

    return range;
}

int main()
{
    int i = 0;
    int *range;

    range = ft_range(42, 100);

    while (range[i])
    {
        printf("%d\n",range[i]);
        i++;
    }
}