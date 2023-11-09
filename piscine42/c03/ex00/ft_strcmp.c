/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:47:51 by asalo             #+#    #+#             */
/*   Updated: 2023/08/22 16:42:15 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)

{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("\n%d", ft_strcmp("A", "a"));
	printf("\n%d", ft_strcmp("a", "a"));
	printf("\n%d", ft_strcmp("a", "A"));
	return (0);
}
*/
