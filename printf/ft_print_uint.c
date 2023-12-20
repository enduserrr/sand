/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:30:11 by asalo             #+#    #+#             */
/*   Updated: 2023/12/20 21:31:24 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_uint(unsigned long n, char *base)
{
	int count;
	int base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n < (unsigned long)base_len)
		return (print_char(base[n]));
	else
	{
		count = print_digit(n / base_len, base);
		return (count + print_digit(n % base_len, base));
	}
}