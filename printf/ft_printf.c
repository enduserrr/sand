/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:24:57 by asalo             #+#    #+#             */
/*   Updated: 2023/12/16 18:29:13 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	transform(const char *str, int i, int *prt, va_list *args)
{
	int	len = 0;

	if (str[i + 1] == 'c')
		len = uputchar(va_arg(*args, int));
	else if (str[i + 1] == 's')
		len = putstr(va_arg(*args, char *));
	else if (str[i + 1] == 'p')
		len = putpointer((long long)va_arg(*args, unsigned long long));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		len = putnbr(va_arg(*args, int));
	else if (str[i + 1] == 'u')
		len = putunsigned(va_arg(*args, unsigned int));
	else if (str[i + 1] == 'x')
		len = put_intbase(va_arg(*args, int), "0123456789abcdef");
	else if (str[i + 1] == 'X')
		len = put_intbase(va_arg(*args, int), "0123456789ABCDEF");
	else if (str[i + 1] == '%' && str[i] == '%')
		len = uputchar('%');
	else
		len = uputchar(str[i + 1]);
	if (len == -1)
		return (-1);
	return (*prt += len);
}

int	ft_printf(const char *str, ...)
{
	int		printed_lengh;
	size_t	i;
	va_list	ap;

	va_start(ap, str);
	i = -1;
	printed_lengh = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			if (transform(str, i++, &printed_lengh, &ap) == -1)
				return (-1);
		}
		else if (i < ft_strlen(str))
		{
			if (uputchar((unsigned char)str[i]) == -1)
				return (-1);
			printed_lengh += 1;
		}
	}
	va_end(ap);
	return (printed_lengh);
}
