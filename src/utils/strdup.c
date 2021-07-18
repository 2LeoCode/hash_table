#include <hash_internals.h>

char	*ft_strdup(const char *s)
{
	const size_t	len = ft_strlen(s);
	char			*dup;

	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup)
		ft_strcpy(dup, s);
	return (dup);
}
