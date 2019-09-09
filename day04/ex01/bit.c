#include "header.h"
#include <stdlib.h> //malloc

int			toInt(char *bits)
{
	int		sum;
	int		mult;

	sum = 0;
	mult = 1;
	for (int i = 5; i >= 0; i--, mult *= 2)
		sum += bits[i] == '1' ? mult : 0;
	return (sum);
}

char		*string_bits(int a)
{
	char	*sum = malloc(sizeof(char) * 7);
	int		num = 32;

	for (int i = 0; i < 6; i++, num >>= 1)
		a & num ? (sum[i] = '1') : (sum[i] = '0');
	sum[6] = '\0';
	return (sum);
}

char		*getSum(char *a, char *b)
{
	int		ai = toInt(a);
	int		bi = toInt(b);
	char	*sum = string_bits(ai + bi);
	return (sum);
}
