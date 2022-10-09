#include "libft.h"

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

void	ft_free(char **str, size_t line)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL && i < line)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_split(char **result, char const *all, char sep, size_t size)
{
	int	i;
	size_t	line;

	if (!all || !size)
		return ;
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
