/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:11:29 by asalo             #+#    #+#             */
/*   Updated: 2023/08/17 17:42:35 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <string.h>*/

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
			i++;
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

    printf("%d\n", ft_str_is_alpha(str));
    printf("%d\n", ft_str_is_alpha(str1));
    printf("%d\n", ft_str_is_alpha(str2));
    return (0);
}
*/
