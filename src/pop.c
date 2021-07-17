#include <hash_internals.h>

bool	hashtable_pop(t_hash *hash, const char *key)
{
	const unsigned int	hash_index = hash->hash_fun(key);

	if (hash->data[hash_index])
		return (lst_pop(hash->data[hash_index], key));
	return (false);
}
