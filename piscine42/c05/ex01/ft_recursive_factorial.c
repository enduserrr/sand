/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:54:46 by asalo             #+#    #+#             */
/*   Updated: 2023/08/24 12:15:52 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)

{
	if ((nb == 0) || (nb == 1))
		return (1);
	else if ((nb > 1) && (nb < 13))
		return (nb * ft_recursive_factorial(nb - 1));
	else
		return (0);
}
/*
#include <stdio.h>

int main(void)

{
    int nb = 12;
    
    printf("%d\n", ft_recursive_factorial(nb));
    return (0);
}
*/