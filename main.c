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
		if (*key < 16)
			hash += *key * 721;
		else if (*key >= 16 && *key < 32)
			hash += *key * 211;
		else if (*key >= 48 && *key < 64)
			hash += *key * 69;
		else if (*key >= 80 && *key < 96)
			hash += *key * 46;
		else if (*key >= 96 && *key < 112)
			hash += *key * 23;
		else
			hash += *key * 61;
		hash *= 42;
		key++;
	}
	hash /= len;
	hash += 42;
	return (hash);
}

int	ft_putstr(const char *s)
{
	return (write(1, s, strlen(s)));
}

int	main(void)
{
	t_hash	*hash_table = hashtable_create(10, hash_function, free);
	char	*s[10] = {
		strdup("jean"),
		strdup("vivien"),
		strdup("titouan"),
		strdup("eudes"),
		strdup("starfoulah"),
		strdup("le coran"),
		strdup("sur pepe"),
		strdup("jvais serrer"),
		strdup("le boubou"),
		strdup("christian")
	};
	for (char key[8] = "0(zh$!D)"; *key <= '9'; ++*key)
	{
		ft_putstr(key);
		write(1, "\n", 1);
		for (unsigned i = 2; i < 7; i++)
			key[i]++;
		hashtable_push(hash_table, key, s[*key - 48]);
	}
	hashtable_print(hash_table, ft_putstr, -1, SIZE_MAX);
	hashtable_destroy(hash_table);
	return (0);
}
