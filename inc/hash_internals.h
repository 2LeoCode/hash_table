#ifndef HASH_INTENRALS_H
# define HASH_INTERNALS_H

# include "hash_table.h"

typedef struct s_node	t_node;

struct	s_node
{
	char	*key;
	void	*data;
	void	(*destructor)();
	t_node	*next;
};

typedef struct s_list
{
	t_node	*head;
	size_t	size;
}	t_list;

struct s_hash
{
	t_list			*data;
	size_t			max_size;
	unsigned int	(*hash_fun)();
	int				(*cmp_fun)();
	void			(*free_fun)();
};

#endif
