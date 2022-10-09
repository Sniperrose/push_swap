#include "../include/push_swap.h"

char    *ft_separate(char *str)
{
        int     i;
        char    *tmp;

        if (!str)
                return (NULL);
        tmp = malloc((ft_strlen(str) + 2) * sizeof(char));
        if (!tmp)
        {
                free(str);
                return (NULL);
        }
        i = 0;
        while (str[i] != '\0')
        {
                tmp[i] = str[i];
                i++;
        }
        tmp[i++] = ' ';
        tmp[i] = '\0';
        free(str);
        return (tmp);
}

char    *ft_joinall(char *str, char const *argv)
{
        char    *all;

        if (!argv)
                return (NULL);
        if (str == NULL)
        {
                all = ft_strdup(argv);
                all = ft_separate(all);
                if (!all)
                        return(NULL);
                return (all);
        }
        else
        {
                str = ft_separate(str);
                if (!str)
                        return (NULL);
                all = ft_strjoin(str, argv);
                if (!all)
                        return (NULL);
        }
        return (all);
}
