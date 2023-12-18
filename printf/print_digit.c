/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:26:45 by asalo             #+#    #+#             */
/*   Updated: 2023/12/18 18:41:09 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return print_digit(-n, base) + 1;
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		return count + print_digit(n % base, base);
	}
}

int	print_digit2(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return print_digit(-n, base) + 1;
	}
	else if (n < base)
		return print_char(symbols[n]);
	else
	{
		count = print_digit2(n / base, base);
		return count + print_digit2(n % base, base);
	}
}

int	print_digit3(unsigned int n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < 10)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		return count + print_digit(n % base, base);
	}
}