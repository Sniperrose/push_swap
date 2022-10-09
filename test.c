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
