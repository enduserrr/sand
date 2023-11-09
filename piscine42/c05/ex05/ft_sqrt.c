/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:36:32 by asalo             #+#    #+#             */
/*   Updated: 2023/08/22 14:51:41 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)

{
	long	i;

	if (nb <= 0)
	{
		return (0);
	}
	if (nb == 1)
	{
		return (1);
	}
	i = 2;
	while (i <= nb / 2)
	{
		if (i * i == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)

{
	long	nb = 2147395600;
	long	nb2 = -25;

	printf("%d\n", ft_sqrt(nb));
	printf("%d\n", ft_sqrt(nb2));
	return (0);
}
*/