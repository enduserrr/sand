/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:05:54 by asalo             #+#    #+#             */
/*   Updated: 2023/11/03 16:39:42 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	i = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	ft_memcpy(cpy, s1, i);
	cpy[i] = '\0';
	return (cpy);
}
