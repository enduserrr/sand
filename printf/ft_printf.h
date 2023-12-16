/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:31:38 by asalo             #+#    #+#             */
/*   Updated: 2023/12/16 18:04:00 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *s);
int			uputchar(unsigned char c);
int			putstr(char *s);
int			putnbr(int n);
int			putunsigned(unsigned int nb);
int			put_intbase(long nbr, char *base);
int			putpointer(unsigned long long nbr);
int			ft_printf(const char *str, ...);

#endif