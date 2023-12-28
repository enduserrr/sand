#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char	*ptr = NULL;
	char	*str = "%d\n aand where to %d??";
	char	*s = "%%%     %%";
	int		i = 0;
	int		j = 0;
	int		k = 0;

	ft_printf("%c\n", 'c');
	printf("%c\n", 'c');
	ft_printf("\n%s\n", "ayo");
	printf("%s\n", "ayo");
	ft_printf("\n%x\n", -42);
	printf("%x\n", -42);
	ft_printf("\n%X\n", -42);
	printf("%X\n", -42);
	ft_printf("\n%%\n");
	printf("%%\n");
	ft_printf("\n%u\n", -42);
	printf("%u\n", -42);
	ft_printf("\n%u\n", 42);
	printf("%u\n", 42);
	ft_printf("\n%p\n", ptr);
	printf("%p\n", ptr);
	ft_printf("\n%i\n", 42);
	printf("%i\n", 42);
	printf("\n");
	i = ft_printf(str, k);
	printf("\n");
	j = printf(str, k);
	printf("\n");
	printf("i = %d and j = %d\n", i, j);
	ft_printf("\n%s\n", s);
	printf("%s\n", s);
	return (0);
}
