/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:24:57 by asalo             #+#    #+#             */
/*   Updated: 2023/12/20 21:37:33 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_format(char type, va_list ap, int temp)
{
	int	count;

	count = 0;
	if (type == 'c')
		temp = print_char(va_arg(ap, int));
	else if (type == 's')
		temp = print_str(va_arg(ap, char *));
	else if (type == 'p')
		temp = print_ptr(va_arg(ap, unsigned long));
	else if (type == 'd' || type == 'i')
		temp = print_digit((long) va_arg(ap, int), "0123456789");
	else if (type == 'u')
		temp = print_digit((long) va_arg(ap, unsigned int), "0123456789");
	else if (type == 'x')
		temp = print_digit((long) va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		temp = print_digit((long) va_arg(ap, unsigned int), "0123456789ABCDEF");
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
			temp = find_format(*(++str), ap, temp);
		else
			temp2 = write(1, str, 1);
		if (temp == -1 || temp2 == -1)
		{
			count = -1;
			break ;
		}
		str++;
		count += temp;
		count += temp2;
	}
	va_end(ap);
	return (count);
}
