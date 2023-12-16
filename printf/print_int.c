/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:57:56 by asalo             #+#    #+#             */
/*   Updated: 2023/12/16 18:04:39 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		if (putstr("-2147483648") == -1)
			return (-1);
		return (11);
	}
	else if (n < 0)
	{
		len += putstr("-");
		n = -n;
	}
	else if (n >= 10)
	{
		len += putnbr(n / 10);
		len += uputchar(n % 10 + '0');
	}
	else
	{
		len += uputchar(n + '0');
	}
	return (len);
}

int	putunsigned(unsigned int nb)
{
	int	len;
	int	temp;

	len = 0;
	if (nb >= 10)
	{
		temp = putnbr(nb / 10);
		if (temp == -1)
			return (-1);
		len += temp;
		if (uputchar((nb % 10) + '0') == -1)
			return (-1);
		len += 1;
	}
	else
	{
		if (uputchar(nb + '0') == -1)
			return (-1);
		len += 1;
	}
	return (len);
}