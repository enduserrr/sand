/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04and05.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:06:28 by asalo             #+#    #+#             */
/*   Updated: 2023/08/31 09:10:07 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

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

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = malloc(sizeof(*src) * (i + 1));
	i = 0;
	while (src[i])
	{
		*(dup + i) = src[i];
		i++;
	}
	*(dup + i) = 0;
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)

{
	int			i;
	t_stock_str	*stab;

	i = 0;
	if (ac < 0)
		ac = 0;
	stab = malloc (sizeof(*stab) * (ac + 1));
	if (stab == NULL)
		return (NULL);
	while (i < ac)
	{
		stab[i].size = ft_strlen(av[i]);
		stab[i].str = av[i];
		stab[i].copy = ft_strdup(stab[i].str);
		i++;
	}
	stab[i].size = 0;
	stab[i].str = 0;
	stab[i].copy = 0;
	return (stab);
}


int	main(int argc, char **argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
	return (0);
}