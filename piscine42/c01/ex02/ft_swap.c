/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:22:16 by asalo             #+#    #+#             */
/*   Updated: 2023/08/23 11:05:21 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)

{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
/*
#include <unistd.h>

int	main(void)

{
	int	a;
	int	b;
	int	temp;

	temp = 1;
	a = 42;
	b = 43;
	ft_swap(&a, &b);
	write(1, &a, 1);
	write(1, &b, 1);
	return (0);
}
*/
