/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:36:00 by asalo             #+#    #+#             */
/*   Updated: 2023/08/28 11:39:22 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)

{
	int	*dest;
	int	i;

	if (min >= max)
		return (0);
	dest = malloc((max - min) * sizeof(int));
	if (dest == 0)
		return (0);
	i = 0;
	while (i < (max - min))
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}
/*
int	ft_size(int start, int end)
{
	int	size;

	size = start - end;
	if (size < 0)
		size *= -1;
	return (size);
}

int		main()
{
	int start;
	int end;
    int *array;
    int i;
    int size;

	start = -1;
	end = 5;
	array = ft_range(start, end);
	i = 0;
    size = ft_size(start, end);
	while(i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
    free (array);
    return (0);
}
*/