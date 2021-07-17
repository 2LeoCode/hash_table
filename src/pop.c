#include <hash_internals.h>

bool	hashtable_pop(t_hash *hash, void *data)
{
	const unsigned int	hash_index = hash->hash_fun(data);

	if (hash->data[hash_index])
		return (lst_pop(hash->data[hash_index], data));
	return (false);
}
