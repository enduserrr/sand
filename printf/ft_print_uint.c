/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:30:11 by asalo             #+#    #+#             */
/*   Updated: 2023/12/22 16:48:17 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned long n, char *base)
{
	int	count;
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n < (unsigned long)base_len)
		return (ft_print_char(base[n]));
	else
	{
		count = ft_print_dg(n / base_len, base);
		return (count + ft_print_dg(n % base_len, base));
	}
}
