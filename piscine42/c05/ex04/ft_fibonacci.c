/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:59:20 by asalo             #+#    #+#             */
/*   Updated: 2023/08/24 16:13:25 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)

{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index > 1)
		return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
	else
		return (0);
}
/*
#include <stdio.h>

int main(void)

{
	int index;

	index = 35;
	printf("%d\n", ft_fibonacci(index));
	return (0);
}
*/