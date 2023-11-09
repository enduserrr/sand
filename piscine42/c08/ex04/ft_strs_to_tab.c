/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:18:24 by asalo             #+#    #+#             */
/*   Updated: 2023/08/30 16:13:43 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

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
/*
int	main(int argc, char **argv)
{
	int			i;
	t_stock_str	*t;

	t = ft_strs_to_tab(argc - 1, argv + 1);
	i = 0;
	while (t[i].str != 0)
	{
		printf("t:%d sz:%d str:%s cp:%s ", i, t[i].size, t[i].str, t[i].copy);
		i++;
	}
	return (0);
}*/
