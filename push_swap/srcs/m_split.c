/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:04:02 by asalo             #+#    #+#             */
/*   Updated: 2024/01/24 15:13:45 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

// Whether or not to use size_t instead of ints?
// Change new_str function to be next_str and add static int to keep count of the position
static size_t	str_count(char *str, char sep)
{
	int	count;
	int	skip;

	count = 0;
	skip = 0;
	while (*str)
	{
		if (*str != sep && skip == 0)
		{
			skip = 1;
			count++;
		}
		else if (*str == sep)
			skip = 0;
		str++;
	}
	return (count);
}

static void	new_str(char **str, size_t *len, char c)
{
	size_t	i;

	*str = *str + *len;
	*len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

/*Mutable split (not static)*/
char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*str;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	new = ft_calloc((str_count(s, c) + 1), sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	str = (char *)s;
	slen = 0;
	while (i < str_count(s, c))
	{
		new_str(&str, &slen, c);
		new[i] = ft_calloc((slen + 1), sizeof(char));
		if (!new[i])
			return (free_array(new));
		ft_strlcpy(new[i], str, slen + 1);
		i++;
	}
	new[i] = NULL;
	return (new);
}