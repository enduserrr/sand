/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:31:38 by asalo             #+#    #+#             */
/*   Updated: 2023/12/22 17:30:08 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_dg(long long int n, char *base);
int	ft_print_uint(unsigned long n, char *base);
int	ft_print_ptr(size_t ptr);
int	ft_printf(const char *str, ...);

#endif