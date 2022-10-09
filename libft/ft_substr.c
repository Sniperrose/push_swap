#include "libft.h"

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