/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:24:57 by asalo             #+#    #+#             */
/*   Updated: 2023/12/13 17:49:51 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	size_t	i;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i] != '\0' && i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			i++;
			len += transform(ap, str[i], &i);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}