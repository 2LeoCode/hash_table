#include "inc/hash_table.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

unsigned int	hash_function(const char *key)
{
	const size_t	len = strlen(key);
	unsigned int	hash;

	hash = 0;
	while (*key)
	{
		hash *= key[1] - *key;
		hash += *key++ - 42;
	}
	hash += len * (len / 2) + len - 128 * len;
	return (hash);
}

int	ft_putstr(const char *s)
{
	return (write(1, s, strlen(s)));
}

int	main(void)
{
	t_hash		*hash_table = hashtable_create(10, hash_function, free);
	const char	*key[10] = {
		"jean",
		"vivien",
		"titouan",
		"eudes",
		"jack",
		"daniels",
		"petrouchka",
		"glorg",
		"julien",
		"christian"
	};
	char		*data[10] = {
		strdup("06 95 87 12 15"),
		strdup("06 35 47 15 67"),
		strdup("07 48 63 28 55"),
		strdup("06 21 22 34 88"),
		strdup("06 63 25 44 78"),
		strdup("06 10 37 84 05"),
		strdup("07 48 99 52 27"),
		strdup("07 15 33 07 69"),
		strdup("06 22 08 44 35"),
		strdup("06 18 90 35 02")
	};

	for (unsigned i = 0; i < 10; i++)
		if (hashtable_push(hash_table, key[i], data[i]))
			return (-1);
	hashtable_print(hash_table, ft_putstr, -1, SIZE_MAX);

	ft_putstr("\n\nfind::[\'jack\'=\'");
	ft_putstr(hashtable_lookup(hash_table, "jack"));
	ft_putstr("\']\n");
	ft_putstr("find::[\'titouan\'=\'");
	ft_putstr(hashtable_lookup(hash_table, "titouan"));
	ft_putstr("\']\n");
	ft_putstr("find::[\'petrouchka\'=\'");
	ft_putstr(hashtable_lookup(hash_table, "petrouchka"));
	ft_putstr("\']\n");

	hashtable_pop(hash_table, "glorg");
	ft_putstr("\n\nremoving \'glorg\' ( poor glorg :( )\n\n");
	hashtable_print(hash_table, ft_putstr, -1, SIZE_MAX);
	hashtable_destroy(hash_table);
	return (0);
}
