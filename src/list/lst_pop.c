#include <hash_internals.h>

bool	lst_pop(t_list *lst_ptr, const char *key)
{
	t_node	*it;
	t_node	*tmp;

	it = lst_ptr->head;
	tmp = NULL;
	while (it)
	{
		if (!ft_strcmp(key, it->key))
		{
			if (tmp)
				tmp->next = it->next;
			else
				lst_ptr->head = it->next;
			if (it->destructor)
				it->destructor(it->data);
			free(it->key);
			free(it);
			lst_ptr->size--;
			return (true);
		}
		tmp = it;
		it = it->next;
	}
	return (false);
}
