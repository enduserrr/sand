/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:43:29 by asalo             #+#    #+#             */
/*   Updated: 2023/08/30 17:52:08 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFERSIZE

void	ft_putchar(char c);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int	    minimum(int a, int b, int c);
void    print_max_square_size(bool **max);

#endif
