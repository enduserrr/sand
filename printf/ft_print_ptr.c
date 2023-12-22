/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:29:40 by asalo             #+#    #+#             */
/*   Updated: 2023/12/20 22:02:55 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(size_t ptr)
{
	size_t	value;
	int		count;
	int		tmp;
	char	*base;

	base = "0123456789abcdef";
	tmp = 0;
	value = (size_t)ptr;
	tmp = write (1, "0x", 2);
	if (tmp == -1)
		return (-1);
	count = ft_print_uint(value, base);
	return (count + 2);
}
