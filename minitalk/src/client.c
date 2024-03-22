/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:36:40 by asalo             #+#    #+#             */
/*   Updated: 2024/03/22 17:09:37 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

/**
 * @brief	The function 'sleep()' and 'usleep()' both hault the program
 * 			execution process for a specified time.
 * 			- 'sleep(0)' deals in seconds
 * 			- 'usleep(0,000,000)' deals in microseconds
*/

void	bit_sender(int pid, char i)
{
	int	bit;

	bit = 0;;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		error_exit(CLIENT_INPUT);
	while (i < argc)
	{
		pid = ft_atol(argv[i]);
		if (pid > INT_MAX || pid < INT_MIN)
			error_exit(SIZE);
		while (argv[1][0] != 0)
			bit_sender(pid, argv[2][i++]);
		bit_sender(pid, '\n');
		i++;
	}
	return (0);
}
