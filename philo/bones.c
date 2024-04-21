/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:19:10 by asalo             #+#    #+#             */
/*   Updated: 2024/04/21 14:43:48 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 5)
		return (error(INPUT_ERR2, NULL));
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if ((av[i][j] < 48 || av[i][j] > 57))
				return (error(INPUT_ERR1, NULL));
			j++;
		}
		i++;
	}
	return (0);
}

void	init_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_destroy(&data->philos[i].lock);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	if (data->tid)
		free(data->tid);
	if (data->philos)
		free(data->philos);
}

int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		init_exit(data);
	return (1);
}

int	compare(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}