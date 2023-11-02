/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:03:05 by asalo             #+#    #+#             */
/*   Updated: 2023/11/02 20:53:36 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d2;
	unsigned char	*s2;

	d2 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		s2 = s2 + len - 1;
		d2 = d2 + len - 1;
		while (len--)
			*d2-- = *s2--;
	}
	else if (src >= dst)
	{
		while (len--)
			*d2++ = *s2++;
	}
	return (dst);
}