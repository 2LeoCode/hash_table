#ifndef HASH_INTENRALS_H
# define HASH_INTERNALS_H

# include "hash_table.h"
# include <stdlib.h>
# include <unistd.h>

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
	void			(*free_fun)();
};

void	ft_bzero(void *m, size_t nbytes);
void	*ft_calloc(size_t size, size_t nbytes);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

void	lst_destroy(t_list *lst_ptr);
void	*lst_find(t_list *lst_ptr, const char *key);
bool	lst_pop(t_list *lst_ptr, const char *key);
int		lst_push(t_list *lst_ptr, const char *key, void *data,
			void (*destructor)());

#endif
