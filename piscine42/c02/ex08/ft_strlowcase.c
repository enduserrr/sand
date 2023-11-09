/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:21:34 by asalo             #+#    #+#             */
/*   Updated: 2023/08/17 18:05:47 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/

char	*ft_strlowcase(char *str)

{
	int	low;

	low = 0;
	while (str[low] != '\0')
	{
		if (str[low] > 64 && str[low] < 91)
		{
			str[low] = str[low] + 32;
		}
		low ++;
	}
	return (str);
}
/*

int main(void)

{
    char    str[] = "Bb";
    char    str1[] = "bb";
    char    str2[] = "bB";

    printf("%s\n", ft_strlowcase(str));
    printf("%s\n", ft_strlowcase(str1));
    printf("%s\n", ft_strlowcase(str2));
    return (0);
}
*/
