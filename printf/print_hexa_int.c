/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:51:05 by asalo             #+#    #+#             */
/*   Updated: 2023/12/16 18:04:49 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	displaynbr(long nb, char *base, int base_size)
{
	long	reste;
	int		printed_len;
	int		temp;

	printed_len = 0;
	if (nb < 0)
		nb = 4294967295 - (nb * -1) + 1;
	reste = nb % base_size;
	nb = nb / base_size;
	if (nb > 0)
	{
		temp = displaynbr(nb, base, base_size);
		if (temp == -1)
			return (-1);
		printed_len += temp;
	}
	temp = uputchar(base[reste]);
	if (temp == -1)
		return (-1);
	printed_len += temp;
	return (printed_len);
}

int	put_intbase(long nbr, char *base)
{
	int	base_size;
	int	len;

	base_size = 0;
	while (base[base_size])
		base_size++;
	len = displaynbr(nbr, base, base_size);
	if (len == -1)
		return (-1);
	return (len);
}