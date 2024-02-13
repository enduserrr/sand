/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:04:02 by asalo             #+#    #+#             */
/*   Updated: 2024/02/13 13:52:27 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	str_count(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**split(char *str, char separator)
{
	int		words_number;
	char	**new_strings;
	int		i;

	i = 0;
	words_number = str_count(str, separator);
	if (!words_number)
		exit(1);
	new_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (NULL == new_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			new_strings[i] = malloc(sizeof(char));
			if (!new_strings[i])
				return (free_array(new_strings));
			new_strings[i++][0] = '\0';
			continue ;
		}
		new_strings[i++] = next_word(str, separator);
	}
	new_strings[i] = NULL;
	return (new_strings);
}