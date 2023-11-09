/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:29:23 by asalo             #+#    #+#             */
/*   Updated: 2023/08/24 12:17:57 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)

{
	int	n;
	int	fct;

	n = 1;
	fct = 1;
	if ((nb < 0) || (nb > 13))
		return (0);
	while (n <= nb)
	{
		fct = n * fct;
		n++;
	}
	return (fct);
}
/*
#include <stdio.h>

int main(void)

{
    int nb;

    nb = 6;
    printf("%d\n", ft_iterative_factorial(nb));
    return (0);
}
*/