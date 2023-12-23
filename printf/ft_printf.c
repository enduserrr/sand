/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:24:57 by asalo             #+#    #+#             */
/*   Updated: 2023/12/23 16:33:38 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_format(char type, va_list ap, int temp)
{
	int	count;

	count = 0;
	if (type == 'c')
		temp = ft_print_char(va_arg(ap, int));
	else if (type == 's')
		temp = ft_print_str(va_arg(ap, char *));
	else if (type == 'p')
		temp = ft_print_ptr(va_arg(ap, unsigned long));
	else if (type == 'd' || type == 'i')
		temp = ft_print_dg((long) va_arg(ap, int), "0123456789");
	else if (type == 'u')
		temp = ft_print_dg((long) va_arg(ap, unsigned int), "0123456789");
	else if (type == 'x')
		temp = ft_print_dg((long) va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		temp = ft_print_dg((long) va_arg(ap, unsigned int), "0123456789ABCDEF");
	else
		temp = write(1, &type, 1);
	if (temp == -1)
	{
		va_end(ap);
		return (-1);
	}
	return (count += temp);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		temp;
	int		temp2;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		temp = 0;
		temp2 = 0;
		if (*str == '%')
			temp = ft_find_format(*(++str), ap, temp);
		else
			temp2 = write(1, str, 1);
		if (temp == -1 || temp2 == -1)
		{
			count = -1;
			break ;
		}
		str++;
		count += temp + temp2;
	}
	va_end(ap);
	return (count);
}

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
