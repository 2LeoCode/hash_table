#include <hash_internals.h>

void	*lst_find(t_list *lst_ptr, const char *key)
{
	t_node	*it;

	it = lst_ptr->head;
	while (it && ft_strcmp(it->key, key))
		it = it->next;
	if (it)
		return (it->data);
	return (NULL);
}
