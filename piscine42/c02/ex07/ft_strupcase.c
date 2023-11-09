/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:12:40 by asalo             #+#    #+#             */
/*   Updated: 2023/08/17 18:04:48 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio>
#include <string.h>
*/

char	*ft_strupcase(char *str)

{
	int	up;

	up = 0;
	while (str[up] != '\0')
	{
		if (str[up] > 96 && str[up] < 123)
		{
			str[up] = str[up] - 32;
		}
		up ++;
	}
	return (str);
}
/*

int main(void)

{
    char    str[] = "Bb";
    char    str1[] = "bb";
    char    str2[] = "bB";

    printf("%s\n", ft_strupcase(str));
    printf("%s\n", ft_strupcase(str1));
    printf("%s\n", ft_strupcase(str2));
    return (0);
}
*/
