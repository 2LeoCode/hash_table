#include <hash_internals.h>

static char	*ft_stpcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = 0;
	return (dst);
}

char	*ft_strcpy(char *dst, const char *src)
{
	ft_stpcpy(dst, src);
	return (dst);
}
