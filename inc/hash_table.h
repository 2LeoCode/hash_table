#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct s_hash	t_hash;

/*
**	The `hashtable_create` function creates a new hash table.
**
**	PARAMETERS:
**	- max_size: the size of the new hash table.
**	- hash_fun: your custom hash function, the function needs to take a char
**		pointer and return an unsigned integer.
**	- free_fun: your function to free the data, the function needs to take
**		one pointer to be freed, it can be for example `free`, from <stdlib.h>
**		(for a pointer allocated with `malloc`).
**		If set to NULL, `hashtable_destroy` will not free the data.
**
**	RETURN VALUES:
**	- An opaque t_hash pointer, the reference to the hash table that will be
**		used for other functions.
**	- NULL in case of bad alloc.
*/
t_hash	*hashtable_create(size_t max_size,
						unsigned int (*hash_fun)(const char *),
						void (*free_fun)());

/*
**	The `hashtable_push` function adds a new element to a hash table.
**
**	PARAMETERS:
**	- hash: the hash table reference. (see `hashtable_create`)
**	- key: the hash key to be used, in form of a string.
**	- data: the data to add to the hash table, in form of a pointer.
**
**	RETURN VALUES:
**	- (0) in case of success.
**	- (1) if the key is a duplicate (it will not be added).
**	- (-1) in case of a bad alloc.
*/
int		hashtable_push(t_hash *hash, const char *key, void *data);

/*
**	The `hashtable_pop` function removes an element from a hash table.
**
**	PARAMETERS:
**	- hash: the hash table reference. (see `hashtable_create`)
**	- key: the hash key of the element to remove from the table.
**
**	RETURN VALUES:
**	- true if the element has been deleted.
**	- false if the element hasn't been found.
*/
bool	hashtable_pop(t_hash *hash, const char *key);

/*
**	The `hashtable_lookup` looks for the index of an element in the hash table
**
**	PARAMETERS:
**	- hash: the hash table reference. (see `hashtable_create`)
**	- key: the hash key of the data to look for.
**
**	RETURN VALUES:
**	- A pointer to the data corresponding to the hash key.
**	- NULL if nothing was found
*/
void	*hashtable_lookup(t_hash *hash, const char *key);

/*
**	The `hashtable_destroy` frees the memory allocated with `malloc` to create
**	the hash table.
**
**	PARAMETERS:
**	- hash: the hash table reference. (see `hashtable_create`)
*/
void	hashtable_destroy(t_hash *hash);

/*
**	The `hashtable_print` is to be used as debug purposes only,
**	it displays the hash table.
**
**	PARAMETERS:
**	- hash: the hash table reference. (see `hashtable_create`)
**	- print_fun: a pointer to the function used to print the data.
**	- fd: the file descriptor to write to (sent to `print_fun`)
**		If fd == -1, print_fun will not receive a fd argument.
**	- size: the size of the data to print (sent to `print_fun`)
**		If size == SIZE_MAX, `print_fun` will not receive a size argument.
**	It means that `print_fun` can be prototyped:
**		- int (int, pointer, int)
**		- int (pointer, int)
**		- int (int, pointer)
**		- int (pointer)
**	depending on which arguments you send to the function.
**
**	RETURN VALUES:
**	- (a non-negative value between 0 and `size`) in case of success.
**	- (-1) in case of failure.
*/
int		hashtable_print(t_hash *hash, int (*print_fun)(), int fd, size_t size);
#endif
