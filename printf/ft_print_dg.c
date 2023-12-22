/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:26:45 by asalo             #+#    #+#             */
/*   Updated: 2023/12/22 16:53:32 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dg(long long int n, char *base)
{
	int	count;
	int	count2;
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		return (ft_print_dg(-n, base) + 1);
	}
	else if (n < base_len)
		return (ft_print_char(base[n]));
	else
	{
		count = ft_print_dg(n / base_len, base);
		if (count == -1)
			return (-1);
		count2 = ft_print_dg(n % base_len, base);
		if (count2 == -1)
			return (-1);
		return (count + count2);
	}
}
