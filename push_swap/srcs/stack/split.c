/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:04:02 by asalo             #+#    #+#             */
/*   Updated: 2024/01/27 18:08:45 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

// Change new_str function to be next_str and add static int to keep count of the position
static size_t	str_count(const *s, char sep)
{
	int		count;
	bool	skip;

	count = 0;
	skip = 0;
	while (*s)
	{
		if (*s != sep && skip == 0)
		{
			skip = 1;
			count++;
		}
		else if (*s == sep)
			skip = 0;
		s++;
	}
	return (count);
}

static void	new_str(char **str, size_t *slen, char c)
{
	size_t	i;

	*str = *str + *slen;
	*slen = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*slen)++;
		i++;
	}
}
/*Mutable split (not static)*/
char	**split(char *s, char c)
{
	char	**new_array;
	char	*str;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	new_array = ft_calloc((str_count(s, c) + 1), sizeof(char *));
	if (!new_array)
		return (NULL);
	i = 0;
	str = (char *)s;
	slen = 0;
	while (i < str_count(s, c))
	{
		new_str(&str, &slen, c);
		new_array[i] = ft_calloc((slen + 1), sizeof(char));
		if (!new_array[i])
			return (NULL);
		ft_strlcpy(new_array[i], str, slen + 1);
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}