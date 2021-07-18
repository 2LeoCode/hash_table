#include <hash_internals.h>

void	lst_destroy(t_list *lst_ptr)
{
	t_node	*it;

	while (lst_ptr->head)
	{
		it = lst_ptr->head->next; 
		if (lst_ptr->head->destructor)
			lst_ptr->head->destructor(lst_ptr->head->data);
		free(lst_ptr->head->key);
		free(lst_ptr->head);
		lst_ptr->head = it;
	}
	lst_ptr->size = 0;
}
