#include "header.h"
#include <string.h> //strlen

int		hash(char *str, int len)
{
	int		res;

	res = 0;
	for (int i = 0; i < len; i++)
		res = (D * res + str[i]) % 5;
	return (res);
}

int		howManyJesus(char *bible, char *jesus)
{
	int		i;
	int		lenJ;
	int		count;
	int		jesusHash;

	lenJ = strlen(jesus);
	count = 0;
	jesusHash = hash(jesus, lenJ);
	while (*bible)
	{
		if (jesusHash == hash(bible, lenJ))
		{
			for (i = 0; i < lenJ; i++)
				if (bible[i] != jesus[i])
					break ;
			if (i == lenJ)
				count++;
		}
		bible += 1;
	}
	return (count);
}
