#include <hash_internals.h>

void	*ft_calloc(size_t size, size_t nbytes)
{
	const size_t	total_size = size * nbytes;
	void	*mem_block;

	mem_block = malloc(total_size + 1);
	if (mem_block)
		ft_bzero(mem_block, total_size);
	return (mem_block);
}
