/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:49:45 by asalo             #+#    #+#             */
/*   Updated: 2024/01/24 15:01:08 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	str_count(const char *str, char c)
{
	int	count;
	int	skip;

	count = 0;
	skip = 0;
	while (*str)
	{
		if (*str != c && skip == 0)
		{
			skip = 1;
			count++;
		}
		else if (*str == c)
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
