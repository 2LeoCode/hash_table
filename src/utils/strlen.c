#include <hash_internals.h>

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr)
		ptr++;
	return ((size_t)ptr - (size_t)s);
}
