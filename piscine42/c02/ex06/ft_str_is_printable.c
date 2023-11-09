/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:49:40 by asalo             #+#    #+#             */
/*   Updated: 2023/08/20 11:14:05 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/

int	ft_str_is_printable(char *str)

{
	int	prnt;

	prnt = 0;
	while (str[prnt] != '\0')
	{
		if (str[prnt] > 31 && str[prnt] < 127)
			prnt++;
		else
			return (0);
	}
	return (1);
}
/*
int main(void)

{
    char    str[] = "\b";
    char    str1[127]; "";
    char    str2[] = "!AYOOOO~";

    printf("%d\n", ft_str_is_printable(str));
    printf("%d\n", ft_str_is_printable(str1));
    printf("%d\n", ft_str_is_printable(str2));
    return (0);
}
*/
