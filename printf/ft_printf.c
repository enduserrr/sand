/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:24:57 by asalo             #+#    #+#             */
/*   Updated: 2023/12/19 17:44:45 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[count])
		count++;
	if (write(1, s, count) == -1)
		return (-1);
	return (count);
}

int	find_type(char type, va_list ap)
{
	int	count;
	
	count = 0;
	if (type == 'c')
		count = print_char(va_arg(ap, int));
	else if (type == 's')
		count = print_str(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		count = print_digit((long)va_arg(ap, int), "0123456789");
	else if (type == 'u')
		count = print_uint((long)va_arg(ap, unsigned int), 10);
	else if (type == 'p')
		type = print_ptr((long long)va_arg(ap, unsigned long long), "0123456789abcdef");
	else if (type == 'x')
		count = print_digit((long)va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')/*sending the char base in the function call*/
		count = print_digit((long)va_arg(ap, unsigned int), "0123456789ABCDEF");
	else/*using print_str voids the need for extra variable temp and error handling (gets done in print_str)*/
		count += print_str(&type);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (str[1] == '%' && *str == '%')/*if more than one %, print the following %*/
			count += print_char(*++str);
		else if (*str == '%')
			count += find_type(*++str, ap);
		else /*print_char function takes an integer c as its argument*/
			count +=print_char(*str);/*const char pointer can be implicitly converted to an integer in C*/
		++str;
	}
	va_end(ap);
	return (count);
}

/*int	main()
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
	/*printf("\n\n");
	ft_printf("%cc%cc%c", 'a', '\t', 'b');
	printf("%cc%cc%c", 'a', '\t', 'b');
	
}*/