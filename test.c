#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t     ft_strlen(char const *str)
{
        int     i;

        if (!str)
                return (0);
        i = 0;
        while (str[i] != '\0')
                i++;
        return (i);
}


size_t	counting_c(const char *s, char c)
{
	size_t	line;
	int		i;

	line = 0;
	i = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (*s != '\0')
	{
		if (*s != c && i == 0)
		{
			line++;
			i = 1;
		}
		if (i == 1 && *s == c)
			i = 0;
		s++;
	}
	return (line);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	substr = malloc ((len + 1) * sizeof(char));
	if (!s || !substr)
		return (NULL);
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

size_t	ft_end(const char *s, char c)
{
	size_t	end;

	end = 0;
	while (*s != c && *s != '\0')
	{
		end++;
		s++;
	}
	return (end);
}

void	ft_free(char **ptr, size_t line)
{
	while (0 < line)
	{
		free(ptr[line]);
		line--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	line;

        if (!s)
                return (NULL);
	result = (char **)malloc((counting_c(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	line = 0;
	while (line < counting_c(s, c) && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		result[line] = ft_substr(s, i, ft_end(&s[i], c));
		if (!result[line])
		{
			ft_free(result, line);
			return (NULL);
		}
		i = i + ft_end(&s[i], c);
		line++;
	}
	result[line] = NULL;
	return (result);
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
                return (NULL);
        nbrs = malloc(*size * sizeof(int));
        if (!nbrs)
        {
                ft_free(split, *size);
                return (NULL);
        }
        i = 0;
        while (split[i] != NULL)
        {
                nb = atoi(split[i]);
                nbrs[i] = nb;
                i++;
        }
        ft_free(split, *size);
        return (nbrs);
}
void     ft_getnumbers(char *all)
{
        char    **result;
        int     i = 0;

        result = ft_split(all, ' ');
        if (!result)
        {
                free(all);
                return ;
        }
        while (result[i] != NULL)
        {
                printf("%s, ", result[i]);
                i++;
        }
        ft_free(result, i);
}
int main (int argc, char **argv)
{
        char    *all;
        // int     *nbrs;
        int     size;

        all = NULL;
        // nbrs = NULL;
        size = 1;
        if (argc <= 0)
                return (0);
        while (size < argc)
        {
                all = ft_joinall(all, argv[size]);
                size++;
        }
        ft_getnumbers(all);
        // nbrs = ft_getnumbers(all, &size);
        printf("size = %d\nall = %s\n", size, all);
        free(all);
        return (0);
}



void	ft_error(int *nbr, int i)
{
	while (--i >= 0)
		nbr[i] = 0;
	printf ("error\n");
	exit(0);
}

int	ft_duplicated(int *nbrs, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nbrs[i] == nbrs[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	ft_count(const char *all, char sep)
{
	int		i;
	size_t	line;
	
	if (!all)
		return (0);
	i = 0;
	line = 0;
	while (*all != '\0' && *all == sep)
		all++;
	while (*all != '\0')
	{
		if (*all != sep && i == 0)
		{
			line++;
			i = 1;
		}
		if (i == 1 && *all == sep)
			i = 0;
		all++;
	}
	return (line);
}


void	ft_free(char **ptr, size_t line)
{
	while (0 < line)
	{
		free(ptr[line]);
		line--;
	}
	free(ptr);
}

size_t	ft_end(const char *s, char c)
{
	size_t	end;

	end = 0;
	while (*s != c && *s != '\0')
	{
		end++;
		s++;
	}
	return (end);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	substr = malloc ((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

void	ft_split(char **result, char const *all, char sep, size_t size)
{
	// char	**result;
	int	i;
	size_t	line;

	if (!all || !size)
		return ;
	// result = (char **)malloc((size + 1) * sizeof(char *));
	// if (!result)
	// 	return (NULL);
	i = 0;
	line = 0;
	while (line < size && all[i] != '\0')
	{
		while (all[i] == sep)
			i++;
		result[line] = ft_substr(all, i, ft_end(&all[i], sep));
		if (!result[line])
		{
			ft_free(result, line);
			return ;
		}
		i = i + ft_end(&all[i], sep);
		line++;
	}
	result[line] = NULL;
}

size_t	ft_getnumbers(const char *all)
{
	// size_t	size;
	// size_t	i;
	size_t	ch;
	char	**result;

	if (!all)
		return (0);
	result = NULL;
	ch = ft_count(all, ' ');
	result = (char **)malloc((ch + 1) * sizeof(char *));
	if (!result)
		return (0);
	ft_split(result, all, ' ', ch + 1);
	if (!result)
		return (0);
	ft_free(result, ch);
	return (ch);
}