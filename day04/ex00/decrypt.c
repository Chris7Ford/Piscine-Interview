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

int			count_ones(char a, char b, char c)
{
	int		count = 0;

	if (a == '1')
		count++;
	if (b == '1')
		count++;
	if (c == '1')
		count++;
	return (count);
}

char		*getSum(char *a, char *b)
{
	char	*sum = malloc(sizeof(char) * 7);
	int		carry = 0;
	int		count;

	sum[6] = '\0';
	for (int i = 5; i >= 0; i--)
	{
		count = count_ones(a[i], b[i], carry);
		if (count % 2 == 0)
		{
			carry = count == 2 ? 1 : 0;
			sum[i] = '0';
		}
		else
		{
			carry = count == 1 ? 0 : 1;
			sum[i] = '1';
		}
	}
	return (sum);
}
