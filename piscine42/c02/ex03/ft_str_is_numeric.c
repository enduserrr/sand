/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:06:40 by asalo             #+#    #+#             */
/*   Updated: 2023/08/17 17:59:00 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h
*/
int	ft_str_is_numeric(char *str)

{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] >= 48 && str[n] <= 57)
			n++;
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
    char    str2[] = "/@$_";

    printf("%d\n", ft_str_is_numeric(str));
    printf("%d\n", ft_str_is_numeric(str1));
    printf("%d\n", ft_str_is_numeric(str2));
    return (0);
}
*/
