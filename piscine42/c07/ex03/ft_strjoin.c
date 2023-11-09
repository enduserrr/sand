/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:21:13 by asalo             #+#    #+#             */
/*   Updated: 2023/08/28 10:21:26 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	total_strlen(int size, char **strs)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		temp += ft_strlen(strs[i]);
		i++;
	}
	return (temp);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (original_dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*array;
	int		i;
	int		length;

	length = total_strlen(size, strs) + (ft_strlen(sep) * (size - 1)) + 1;
	if (size == 0)
	{
		array = (char *)malloc(1);
		array[0] = '\0';
		return (array);
	}
	array = (char *)malloc(length * sizeof(char));
	if (array == 0)
		return (0);
	array[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(array, strs[i]);
		if (i + 1 < size)
			ft_strcat(array, sep);
		i++;
	}
	return (array);
}

#include <stdio.h>
#include <unistd.h> 

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	char	*tab[4];
	char	*new;

	tab[0] = "testing";
	tab[1] = "if";
	tab[2] = "this";
	tab[3] = "works";
		new = ft_strjoin(4, tab, " | ");
	ft_putstr(new);
	ft_putstr("\n");
	//printf("%s\n",new);
	free(new);
}
/*#include <stdio.h>
int    main(int ac, char **av)
{
printf ( "%s\n", ft_strjoin(ac, av, "..."));
}*/