/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:24:57 by asalo             #+#    #+#             */
/*   Updated: 2023/12/18 18:37:00 by asalo            ###   ########.fr       */
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
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

int	print_format(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = print_char(va_arg(ap, int));
	else if (type == 's')
		count = print_str(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		count = print_digit((long)va_arg(ap, int), 10);
	else if (type == 'u')
		count = print_digit3((long)va_arg(ap, unsigned int), 10);
	else if (type == 'x')
		count = print_digit((long)va_arg(ap, unsigned int), 16);
	else if (type == 'X')
		count = print_digit2((long)va_arg(ap, unsigned int), 16);
	else
		count += write(1, &type, 1);
	return count;
}

int	my_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, ap);
		else 
			count += write(STDOUT_FILENO, format, 1);
		++format;
	}
	va_end(ap);
	return count;
}

int	main()
{
	int				count;

	my_printf("My s -> %s\n", "John");
	printf("Real s -> %s\n", "John");
	my_printf("My c -> %c\n", 'a');
	printf("Real c -> %c\n", 'a');
	my_printf("My d -> %d\n", 42);
	printf("Real d -> %d\n", 42);
	my_printf("My i -> %i\n", -99);
	printf("Real i -> %i\n", -99);
	my_printf("My u -> %u\n", -1);
	printf("Real u -> %u\n", -1);
	printf("\n\n");
	count = my_printf("My x \n%x\n", -1);
	count = printf("Real x \n%x\n", -1);
	count = my_printf("My X \n%X\n", -1);
	count = printf("Real X \n%X\n", -1);
}
