/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:38:32 by asalo             #+#    #+#             */
/*   Updated: 2023/08/22 16:46:31 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (((i < n) && (s1[i] != '\0') && (s1[i] == s2[i])))
	{	
		i++;
	}
	if (n == i)
		return (0);
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>

int	main(void)

{
	char	s1[] = "aaCds";
	char	s2[] = "aZc";

	printf("%d\n", ft_strncmp(s1, s2, 2));
}
*/
