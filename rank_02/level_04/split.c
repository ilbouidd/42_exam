#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int count_word(char *str)
{
    int i = 0;
    int res = 0;
    int count = 0;

    while (str[i])
    {
        if (str[i] <= 32)
            count = 0;
        else if (!(str[i] <= 32) && count == 0)
        {
            count = 1;
            res++;
        }
        i++;
    }
    return(res);
}

char    *inside(char *str, int debut, int fin)
{
    int len = fin - debut;
    char *res;
    int i = 0;

    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    while (debut < fin)
    {
        res[i] = str[debut];
        i++;
        debut++;
    }
    res[debut] = '\0';
    return (res);
}

char    **ft_split(char *str)
{
    int i = 0;
    int debut = -1;
    int j = 0;
    char    **tab;
    int len = count_word(str);

    tab = malloc(sizeof(char *) * (len + 1));
    if (!tab)
        return (NULL);
    while (i <= ft_strlen(str))
    {
        if (str[i] > 32 && debut < 0)
            debut = i;
        else if ((str[i] <= 32 || i == ft_strlen(str)) && debut >= 0)
        {
            tab[j] = inside(str, debut, i);
            debut = -1;
            j++;
        }
        i++;
    }
    tab[j] = NULL;
    return (tab);
}

 #include <stdio.h>

int main (int ac, char **av)
{
    char **tab;
    int i = 0;
    (void)ac;
    // printf("%d\n",count_word(av[1]));
    // printf("%s\n", inside(av[1], 5, 10));

    tab = ft_split(av[1]);
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
}