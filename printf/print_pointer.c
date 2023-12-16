/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:49:32 by asalo             #+#    #+#             */
/*   Updated: 2023/12/16 18:21:25 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	displaynbr(long long nb, char *base, int base_size)
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
int	putpointer(unsigned long long nbr)
{
	char	*base;
	int		base_size;
	int		printed_len;
	int		temp;

	base = "0123456789abcdef";
	if (nbr == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	base_size = 0;
	while (base[base_size])
		base_size++;
	printed_len = 0;
	if (putstr("0x") == -1)
		return (-1);
	printed_len += 2;
	temp = displaynbr(nbr, base, base_size);
	if (temp == -1)
		return (-1);
	return (printed_len + temp);
}