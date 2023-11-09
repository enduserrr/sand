/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:18:50 by asalo             #+#    #+#             */
/*   Updated: 2023/08/24 13:20:48 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)

{
	int	n;

	n = nb;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	while (power > 1)
	{
		n = n * nb;
		power--;
	}
	return (n);
}
/*
#include <stdio.h>
int main(void)

{
    int nb;
    int power;

    nb = 10;
    power = 3;
    printf("%d\n", ft_iterative_power(nb, power));
    return (0);
}
*/