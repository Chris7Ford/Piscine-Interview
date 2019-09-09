#include "header.h"
#include <stdio.h>

int		main(void)
{
	char	*str;

	str = console();
	printf("The sent message:\n%s\n", str);
	return (0);
}
