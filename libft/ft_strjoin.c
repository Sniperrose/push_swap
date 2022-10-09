#include "libft.h"

char    *ft_strjoin(char *all, char const *argv)
{
        char    *str;
        int     i;
        int     j;

        if (!all && !argv)
                return (NULL);
        str = malloc((ft_strlen(all) + ft_strlen(argv) + 1) * sizeof(char));
        if (!str)
        {
                free(all);
                return (NULL);
        }
        i = 0;
        while (all[i] != '\0')
        {
                str[i] = all[i];
                i++;
        }
        j = 0;
        while (argv[j] != '\0')
                str[i++] = argv[j++];
        str[i] = '\0';
        free (all);
        return (str);
}