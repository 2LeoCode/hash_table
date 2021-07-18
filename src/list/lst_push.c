#include <hash_internals.h>

int	lst_push(t_list *lst_ptr, const char *key, void *data,
		void (*destructor)())
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node)
		new_node->key = ft_strdup(key);
	if (!new_node || !new_node->key)
	{
		free(new_node);
		return (-1);
	}
	new_node->data = data;
	new_node->destructor = destructor;
	new_node->next = lst_ptr->head;
	lst_ptr->head = new_node;
	return (0);
}
