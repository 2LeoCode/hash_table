#include <hash_internals.h>

t_hash	*hashtable_create(size_t max_size, unsigned int (*hash_fun)(const char *),
					void (*free_fun)())
{
	t_hash	*new_hashtable;

	new_hashtable = malloc(sizeof(t_hash));
	if (!new_hashtable)
		return (NULL);
	new_hashtable->max_size = max_size;
	new_hashtable->hash_fun = hash_fun;
	new_hashtable->free_fun = free_fun;
	new_hashtable->data = ft_calloc(max_size, sizeof(t_list));
	if (new_hashtable->data)
		return (new_hashtable);
	free(new_hashtable);
	return (NULL);
}
