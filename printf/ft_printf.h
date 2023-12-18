/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:31:38 by asalo             #+#    #+#             */
/*   Updated: 2023/12/18 18:29:52 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	print_char(int c);
int	print_str(char *s);
int	print_digit(long n, int base);
int	print_digit2(long n, int base);
int	print_digit3(unsigned int n, int base);
int	print_format(char type, va_list ap);
int	ft_printf(const char *str, ...);

#endif