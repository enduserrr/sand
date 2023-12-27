#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int		count;
	void	*ptr;

	count = 0;
	ptr = &count;
	ft_printf("\ntest: %s\n", "ayo");
	printf("real: %s\n", "ayo");
	ft_printf("\ntest: %x\n", -42);
	printf("real: %x\n", -42);
	ft_printf("\ntest: %X\n", -42);
	printf("real: %X\n", -42);
	ft_printf("\ntest: %%\n");
	printf("real: %%\n");
	ft_printf("\ntest: %u\n", -42);
	printf("real: %u\n", -42);
	ft_printf("\ntest: %u\n", 42);
	printf("real: %u\n", 42);
	ft_printf("\ntest: %p\n", &ptr);
	printf("real: %p\n", &ptr);
	ft_printf("\ntest: %i\n", 42);
	printf("real: %i\n", 42);
	return (0);
}