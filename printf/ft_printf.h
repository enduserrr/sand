/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:31:38 by asalo             #+#    #+#             */
/*   Updated: 2023/12/13 18:10:29 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

/* print functions */
int		ft_print_char(unsigned char c);
int		ft_print_str(char *s);
int		ft_print_int(int nb);
int		ft_print_int_base(long nbr, char *base);
int		ft_print_ptr(unsigned long long nbr);
int		ft_print_uint(unsigned int nb);

/* utils */
size_t	ft_strlen(const char *s);

#endif