/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:51:13 by asalo             #+#    #+#             */
/*   Updated: 2023/12/10 14:22:11 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cpy_to_stash(char *stash, char *buf)
{
	char	*temp;
	char	*res;

	res = NULL;
	if (!stash && buf)
	{
		res = ft_strdup(buf);
		return (free_premium(&res, 1));
	}
	temp = free_premium(&stash, 1);
	if (!temp)
		return (free_premium(&temp, 0));
	res = ft_strjoin(temp, buf);
	if (!res)
		free(res);
	free(temp);
	return (res);
}

static char	*extract(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (free_premium(&stash, 0));
	while (stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free_premium(&line, 0));
	j = 0;
	while (j < i + 1)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*recreate(char *stash)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n')
		i++;
	if (stash[i + 1] == '\0')
		return (free_premium(&stash, 0));
	res = ft_substr(stash, i + 1, ft_strlen(stash));
	free_premium(&stash, 0);
	if (!res)
		return (NULL);
	return (res);
}

static int	check_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	long		ret;
	static char	*stash = NULL;
	static char	*line;

	line = 0;
	ret = BUFFER_SIZE;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret <= 0 && !stash) || ret == -1)
			return (free_premium(&stash, 0));
		buf[ret] = '\0';
		stash = cpy_to_stash(stash, buf);
		if (check_nl(stash))
		{
			line = extract(stash);
			if (!line)
				return (free_premium(&stash, 0));
			return (stash = recreate(stash), line);
		}
	}
	return (free_premium(&stash, 1));
}