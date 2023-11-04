/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:54:26 by asalo             #+#    #+#             */
/*   Updated: 2023/11/02 15:09:46 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (n == i)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include <stdio.h>

int	main(void)

{
	char	s1[] = "A";
	char	s2[] = "a";

	printf("%d\n", ft_strncmp(s1, s2, 2));
}
*/
