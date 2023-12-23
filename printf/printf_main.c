#include "ft_printf.h"

int	main(void)
{
	int x = 50;
	int *ptr = &x;
	int	my_age;
	void *nptr;

	x= 50;
	ptr = &x;
	my_age = 1;
	nptr = NULL;
	ft_printf("\nTest s: %s\n", "John");
	printf("Real s: %s\n\n", "John");
	ft_printf("Test c: %c\n", 'a');
	printf("Real c: %c\n\n", 'a');
	ft_printf("Test d: %d\n", 42);
	printf("Real d; %d\n\n", 42);
	ft_printf("Test i: %i\n", -99);
	printf("Real i: %i\n\n", -99);
	ft_printf("Test u: %u\n", -1);
	printf("Real u: %u\n\n", -1);
	ft_printf("Test x: %x\n", -1);
	printf("Real x: %x\n\n", -1);
	ft_printf("Test X: %X\n", -2);
	printf("Real X: %X\n\n", -2);
	ft_printf("Test: the %% character %%%%\n");
	printf("Real: the %% character %%%%\n");
	ft_printf("Test p: %p\n", &my_age);
	printf("Real p: %p\n", &my_age);
	ft_printf("Test p: %p\n", &nptr);
	printf("Real p: %p\n", &nptr);
	ft_printf("The address is: %p, the value is %d\n", ptr, *ptr);
	printf("The address is: %p, the value is %d\n", ptr, *ptr);
	return (0);
}