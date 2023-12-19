/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:26:45 by asalo             #+#    #+#             */
/*   Updated: 2023/12/19 17:43:09 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, char *base)
{
	int	count;
	int	base_size;

	base_size = 0;
	while (base[base_size])
		base_size++;
	if (n < 0)
	{
		print_char('-');
		return (print_digit(-n, base) + 1);
	}
	else if (n < base_size)
			return (print_char(base[n]));
	else
	{
		count = print_digit(n / base_size, base);
		return (count + print_digit(n % base_size, base));
	}
}

int	print_uint(unsigned int n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		print_char('-');
		return (print_uint(-n, base) + 1);
	}
	else if (n < 10)
		return (print_char(symbols[n]));
	else
	{
		count = print_uint(n / base, base);
		return (count + print_uint(n % base, base));
	}
}
int	print_ptr(unsigned long long n, char *base)
{
	int					count;
	unsigned long long	base_size;

	base_size = 0;
	if (n == 0)
		return (print_str("0x0"));
	while (base[base_size])
		base_size++;
	if (print_str("0x") == -1)
		return (-1);
	n += 2;
	if (n < 0)
	{
		print_char('-');
		return (print_digit(-n, base) + 1);
	}
	else if (n < base_size)
			return (print_char(base[n]));
	else
	{
		count = print_digit(n / base_size, base);
		return (count + print_digit(n % base_size, base));
	}
}