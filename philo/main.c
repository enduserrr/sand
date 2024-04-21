/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:51:21 by asalo             #+#    #+#             */
/*   Updated: 2024/04/21 14:52:27 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	case_one(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (error(THREAD_ERR1, data));
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		usleep(0);
	init_exit(data);
	return (0);
}

int	main(int ac, char **av)
{
	static t_data	*data;

	if (check_input(ac, av))
		return (1);
	if (init(data, av, ac))
		return (1);
	if (data->philo_num == 1)
		return (case_one(data));
	if (thread_init(data))
		return (1);
	init_exit(data);
	return (0);
}