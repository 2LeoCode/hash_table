#include <hash_internals.h>

void	ft_bzero(void *m, size_t nbytes)
{
	uint64_t	*qwrd;
	char		*s;

	qwrd = (uint64_t *)m;
	while (nbytes >= 8)
	{
		*qwrd++ = 0;
		nbytes -= 8;
	}
	s = (char *)qwrd;
	while (nbytes--)
		*s++ = 0;
}
