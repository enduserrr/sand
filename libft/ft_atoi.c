/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:25:18 by asalo             #+#    #+#             */
/*   Updated: 2023/11/17 10:06:14 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * sign);
}
/*int main(void)

{
    int str1;
	int	str2;
	int	str3;
	int	str4;
	int	str5;

    str1 = ft_atoi("+12B39999949");
	str2 = ft_atoi("2147483647");
	str3 = ft_atoi("-2147483648");
	str4 = ft_atoi("-+-2147483644");
	str5 = ft_atoi("2147483650");
	printf("%d\n", str1);
	printf("%d\n", str2);
	printf("%d\n", str3);
	printf("%d\n", str4);
	printf("%d\n", str5);
	printf("%d\n", atoi("2147483650"));
    return (0);
}*/