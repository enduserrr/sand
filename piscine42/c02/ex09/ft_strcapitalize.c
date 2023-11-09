/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 09:38:21 by asalo             #+#    #+#             */
/*   Updated: 2023/08/20 10:52:07 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


char	*ft_strcapitalize(char *str)

{
	int	i;

	if (str[0] > 96 && str[0] < 123)
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] += 32;
		if (str[i] > 96 && str[i] < 123)
		{
			if (!(str[i - 1] > 96 && str[i - 1] < 123))
			{
				if (!(str[i - 1] > 47 && str[i - 1] < 58))
				{
					if (!(str[i - 1] < 91 && str[i - 1] > 64))
					{
						str[i] -= 32;
					}
				}			
			}
		}
		i++;
	}
	return (str);
}

int		main(void)

{
	char	str[] = "hello worlDDDDD!";
    char	str2[] = "can yoU CApitalise this Or wHat?";

	printf("%s\n", ft_strcapitalize(str));
    printf("%s\n", ft_strcapitalize(str2));
    return (0);
}