#include <hash_internals.h>

int	hashtable_push(t_hash *hash, const char *key, void *data)
{
	unsigned int	hash_index;

	hash_index = hash->hash_fun(data);
	if (hash_index >= hash->max_size)
		hash_index %= hash->max_size;
	if (lst_find(&hash->data[hash_index], key))
		return (1);
	if (!lst_push(&hash->data[hash_index], key, data, hash->free_fun))
		return (0);
	hashtable_destroy(hash);
	return (-1);
}
