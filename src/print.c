#include <hash_internals.h>

int	hashtable_print(t_hash *hash, int (*print_fun)(), int fd, size_t size)
{
	const int		wfd = fd + 2 * (fd == -1);
	const t_node	*it;
	unsigned int	i;
	int				tmp;
	int				ret;

	i = -1;
	ret = 0;
	tmp = 0;
	while (++i < hash->max_size)
	{
		it = hash->data[i].head;
		if (!it)
			tmp = write(wfd, "(uninitialized)", 15);
		else
		{
			while (it)
			{
				write(1, "[\'", 2);
				write(1, it->key, ft_strlen(it->key));
				write(1, "\'=\'", 3);
				if (fd >= 0 && size != SIZE_MAX)
					(*print_fun)(fd, it->data, size);
				else if (fd >= 0)
					(*print_fun)(fd, it->data);
				else if (size != SIZE_MAX)
					(*print_fun)(it->data, size);
				else
					(*print_fun)(it->data);
				write(1, "\']", 2);
				it = it->next;
				if (it)
					tmp = write(wfd, ", ", 2);
			}
		}
		if (tmp == -1)
			return (-1);
		ret += tmp;
		tmp = write(wfd, "\n", 1);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	return (ret);
}
