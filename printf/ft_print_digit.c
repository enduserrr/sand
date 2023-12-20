/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:26:45 by asalo             #+#    #+#             */
/*   Updated: 2023/12/20 21:36:49 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_digit(long long int n, char *base)
{
	int count;
	int count2;
	int base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n < 0)
	{
		if (print_char('-') == -1)
			return (-1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base_len)
		return (print_char(base[n]));
	else
	{
		count = print_digit(n / base_len, base);
		if (count == -1)
			return (-1);
		count2 = print_digit(n % base_len, base);
		if (count2 == -1)
			return (-1);
		return (count + count2);
	}
}
