#include <hash_internals.h>

bool	hashtable_pop(t_hash *hash, const char *key)
{
	const unsigned int	hash_index = hash->hash_fun(key) % hash->max_size;

	return (lst_pop(&hash->data[hash_index], key));
}
