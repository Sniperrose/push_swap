#include "libft.h"

char    *ft_strdup(char const *argv)
{
        char    *tmp;
        int     i;

        if (!argv)
                return (NULL);
        tmp = malloc((ft_strlen(argv) + 1) * sizeof(char));
        if (!tmp)
                return (NULL);
        i = 0;
        while (argv[i] != '\0')
        {
                tmp[i] = argv[i];
                i++;
        }
        tmp[i] = '\0';
        return (tmp);
}