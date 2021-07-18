#include <hash_internals.h>

bool	lst_pop(t_list *lst_ptr, const char *key)
{
	t_node	*it;
	t_node	*prev;

	it = lst_ptr->head;
	prev = NULL;
	while (it)
	{
		if (!ft_strcmp(key, it->key))
		{
			if (prev)
				prev->next = it->next;
			else
				lst_ptr->head = it->next;
			if (it->destructor)
				it->destructor(it->data);
			free(it->key);
			free(it);
			lst_ptr->size--;
			return (true);
		}
		prev = it;
		it = it->next;
	}
	return (false);
}
