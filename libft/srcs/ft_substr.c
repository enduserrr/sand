/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:29:06 by asalo             #+#    #+#             */
/*   Updated: 2023/11/02 20:53:34 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	fullsize;
	size_t	endpoint;

	if (!s)
		return (NULL);
	fullsize = ft_strlen(s);
	endpoint = 0;
	if (start < fullsize)
		endpoint = fullsize - start;
	if (endpoint > len)
		endpoint = len;
	substr = (char *)malloc(sizeof(char) * (endpoint + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, endpoint + 1);
	return (substr);
}