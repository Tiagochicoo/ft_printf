#include <stdio.h>
#include <stdlib.h>
#include "./includes/ft_printf.h"

int main(void)
{
	int len, len2;

	len = ft_printf("%c", '0');
	printf("\n");
	len2 = printf("%c", '0');
	printf("\n");
	if (len != len2)
	{
		printf("Lengths differ. -> %d \n", len - len2);
		return (1);
	}
	return (0);
}
