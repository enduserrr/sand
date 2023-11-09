/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:48:29 by asalo             #+#    #+#             */
/*   Updated: 2023/08/30 16:13:10 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)


{
	write(1, &c, 1);
}

void	ft_putstr(char *str)

{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)

{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
		if ((nb / 10) != 0)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + (nb % 10));
	}
}

void	ft_show_tab(struct s_stock_str *par)

{
	int		i;

	i = 0;
	if (par == NULL)
		return ;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	t_stock_str	*tab;

	tab = ft_strs_to_tab(argc - 1, argv + 1);
	ft_show_tab(tab);
	return (0);
}
*/
