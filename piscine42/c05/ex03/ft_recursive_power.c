/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:21:43 by asalo             #+#    #+#             */
/*   Updated: 2023/08/24 14:17:09 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)

{
	if (power == 0)
	{
		return (1);
	}
	else if (power < 0)
	{
		return (0);
	}
	else if (power > 1)
	{
		return (nb * ft_recursive_power(nb, --power));
	}
	return (nb);
}
/*
#include <stdio.h>

int main(void)

{
    int n;
    int p;

    n = 1000;
    p = 3;
    printf("%d\n", ft_recursive_power(n, p));
    return (0);
}
*/