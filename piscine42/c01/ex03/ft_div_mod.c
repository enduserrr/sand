/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:06:40 by asalo             #+#    #+#             */
/*   Updated: 2023/08/23 11:18:15 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)

{	
	*div = (a / b);
	*mod = (a % b);
}
/*
#include <stdio.h>

int	main(void)
{
	int a;
	int b;
	int mod;
	int div;

	a = 6;
	b = 2;
	ft_div_mod(a, b, &div, &mod);
	printf("a : %d, b : %d, div : %d, mod : %d\n", a, b, div, mod);
	return (0);
}
*/
