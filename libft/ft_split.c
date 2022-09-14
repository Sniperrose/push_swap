#include "libft.h"

size_t	counting_c(const char *s, char c)
{
	size_t	line;
	int	i;

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

char	**ft_split(char const *str, char c)
{
	char	**result;
	size_t	i;
	size_t	line;

	result = (char **)malloc((counting_c(str, c) + 1) * sizeof(char *));
	if (!str || !result)
		return (NULL);
	i = 0;
	line = 0;
	while (line < counting_c(str, c) && str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		result[line] = ft_substr(str, i, ft_end(&str[i], c));
		if (!result[line])
		{
			ft_free(result, line);
			return (NULL);
		}
		i = i + ft_end(&str[i], c);
		line++;
	}
	result[line] = NULL;
	return (result);
}
