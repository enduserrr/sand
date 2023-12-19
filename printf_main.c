int	main()
{
	int	my_age;

	my_age = 1;
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
	ft_printf("Test: A %% character.\n");
	printf("Real: A %% character.\n");
	ft_printf("Test p: %p\n", &my_age);
	printf("Real p: %p\n", &my_age);
	printf("\n\n");
	ft_printf("%cc%cc%c", 'a', '\t', 'b');
	printf("%cc%cc%c", 'a', '\t', 'b');
	
}