/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:30:00 by asalo             #+#    #+#             */
/*   Updated: 2023/08/17 18:01:08 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
int	ft_str_is_lowercase(char *str)

{
	int	l;

	l = 0;
	while (str[l] != '\0')
	{
		if (str[l] >= 97 && str[l] <= 122)
			l++;
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

    printf("%d\n", ft_str_is_lowercase(str));
    printf("%d\n", ft_str_is_lowercase(str1));
    printf("%d\n", ft_str_is_lowercase(str2));
    return (0);
}
*/
