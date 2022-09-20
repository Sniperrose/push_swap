#include "../include/push_swap.h"

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

	result = (char **)malloc((counting_c(s, c) + 1) * sizeof(char *));
	if (!s || !result)
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

int	ft_size(int	count, char **str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while(i < count)
	{
		len += ft_strlen(str[i]);
		i++;
	}
	return (len + i);
}

char	*ft_joinall(int count, char **str)
{
	char	*tmp = NULL;
	int		i;

	tmp = (char *)malloc(ft_size(count, str) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count)
	{
		tmp = ft_strjoin(tmp, str[i]);
		if (i < (count - 1))
			tmp = ft_strjoin(tmp, " ");
		i++;
	}
	return (tmp);
}
// int	ft_dupcheck(int *tmp, int n, int i)
// {
// 	int	j = 0;
// 	while (j <= i)
// 	{
// 		if (tmp[j] == n)
// 			return (-1);
// 		j++;
// 	}
// 	return (0);
// }
// long int	ft_atoi(char *nptr)
// {
// 	int	i;
// 	int	sign;
// 	long	num;

// 	i = 0;
// 	num = 0;
// 	sign = 1;
// 	while ((nptr[i] > 7 && nptr[i] < 14) || (nptr[i] == 32))
// 		i++;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 	{
// 		if (nptr[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (nptr[i])
// 	{
// 		if (nptr[i] > '9' || nptr[i] < '0')
// 			return (-21474836480);
// 		num = 10 * num + (nptr[i] - '0');
// 		i++;
// 	}
// 	return (num * sign);
// }

// int	ft_input(char **argv, int *tmp)
// {
// 	int	i = 0;
// 	long int	n = 0;

// 	while (argv[i + 1])
// 	{
// 		n = ft_atoi(argv[i + 1]);
// 		if (n < -2147483648 || n > 2147483647 || 
// 				ft_dupcheck(&tmp[0], n, i) != 0)
// 			return (-1);
// 		tmp[i] = n;
// 		i++;
// 	}
// 	return (i);
// }
