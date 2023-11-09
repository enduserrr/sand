/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:40:14 by asalo             #+#    #+#             */
/*   Updated: 2023/08/17 18:02:20 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
int	ft_str_is_uppercase(char *str)

{
	int	uc;

	uc = 0;
	while (str[uc] != '\0')
	{
		if (str[uc] > 64 && str[uc] < 91)
			uc++;
		else
			return (0);
	}
	return (1);
}
/*

int main(void)

{
    char    str[] = "ceststr";
    char    str1[] = "1239";
    char    str2[] = "AYOOOO";

    printf("%d\n", ft_str_is_uppercase(str));
    printf("%d\n", ft_str_is_uppercase(str1));
    printf("%d\n", ft_str_is_uppercase(str2));
    return (0);
}
*/
