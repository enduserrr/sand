/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:23:35 by asalo             #+#    #+#             */
/*   Updated: 2023/08/23 11:19:54 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)

{
	int	div;
	int	mod;

	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	n1 = 6;
	int	n2 = 2;
	int	*a = &n1;
	int	*b = &n2;
	
	ft_ultimate_div_mod(a, b);

	printf("a: %d\n", *a);
	printf("b: %d\n", *b);
}
*/
