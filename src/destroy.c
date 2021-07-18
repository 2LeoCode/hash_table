#include <hash_internals.h>

void	hashtable_destroy(t_hash *hash)
{
	unsigned int	i;

	i = -1;
	while (++i < hash->max_size)
		lst_destroy(&hash->data[i]);
	free(hash->data);
	hash->max_size = 0;
	hash->hash_fun = NULL;
	hash->free_fun = NULL;
	free(hash);
}
