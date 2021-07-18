#include <hash_internals.h>

void	*hashtable_lookup(t_hash *hash, const char *key)
{
	const unsigned int	hash_index = hash->hash_fun(key) % hash->max_size;

	return (lst_find(&hash->data[hash_index], key));
}
