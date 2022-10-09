#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int     ft_strlen(char const *str)
{
        int     i;

        if (!str)
                return (0);
        i = 0;
        while (str[i] != '\0')
                i++;
        return (i);
}

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

char    *ft_joinall(char *str, char const *argv)
{
        char    *all;
//      int     i;

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
/*      {
                i = 0;
                all = malloc((ft_strlen(argv) + 2) * sizeof(char));
                if (!all)
                        return (NULL);
                while (argv[i] != '\0')
                {
                        all[i] = argv[i];
                        i++;
                }
                all[i++] = ' ';
                all[i] = '\0';
                return (all);
        }*/
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
/*
char    *ft_getnumbers(char **argv, int *size)
{
        int     i;
        char    *all;

        if (!argv || !*argv)
                return (NULL);
        i = 0;
        all = ft_joinall(argv, size);
        if (!all)
                return (NULL);
        *size = 0;
        while (all)
        {
                if (all[i] == ' ')
                        *size += 1;
                i++;
        }
        return (all);
}*/

int     *ft_getvalue(char **split, int *size)
{
        int     i;
        int     nb;
        int     *nbrs;

        if (!split || !*split)
                return [NULL];
        nbrs = malloc(size * sizeof(int));
        if (!nbrs)
        {
                ft_free(split, size);
                return (NULL);
        }
        i = 0;
        while (split[i] != NULL)
        {
                if (ft_isascii(split[i][0]))
                {
                        ft_error(nbrs, split, size);
                        return (NULL);
                }
                nb = ft_atoi2(split[i]);
                if (min max s ih bol)
                {
                        ft_error(nbrs, split, size);
                        return (NULL);
                }
                nbrs[i] = nb;
                i++;
        }
        ft_free(split, size);
        return (nbrs);
}
int     *ft_getnumbers(char *all, int *size)
{
        int     *nbrs;
        char    **split;

        if (!all)
                return (NULL);
        split = ft_split(all, " ", size);
        if (!split)
        {
                free(all);
                return (NULL);
        }
        nbrs = ft_getvalue(split, size);
        if (!nbrs)
        {
                ft_free(split, size);
                return (NULL);
        }
        ft_free(split, size);
        return (nbrs);
}
int main (int argc, char **argv)
{
        char    *all;
        int     *nbrs;
        int     size;

        nbrs = NULL;
        size = 1;
        if (argc <= 0)
                return (0);
        while (size < argc)
        {
                all = ft_joinall(all, argv[size]);
                size++;
        }
        nbrs = ft_getnumbers(all, &size);
        ft_printf(nbrs, size);
        printf("size = %d\nall = %s\n", size, nbrs);
        free(all);
        free(nbrs);
        return (0);
}
