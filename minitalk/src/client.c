/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:36:40 by asalo             #+#    #+#             */
/*   Updated: 2024/03/22 18:35:02 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

static void	error_exit(e_type type)
{
	if (type == CLEAN_EXIT)
		exit(0);
	if (type == CLIENT_INPUT)
	{
		ft_putstr_fd("\033[91mError: incorrect format.\033[0m\n", 2);
		ft_putstr_fd("Try: ./client <PID> <MESSAGE>\n", 1);
		ft_putstr_fd("(if server isn't initialised, first run the following commnd:\n", 1);
		ft_putstr_fd("-> ./server\n", 1);
		exit(1);
	}
	if (type == SERVER_INPUT)
	{
		ft_putstr_fd("\033[91mError: incorrect format.\033[0m\n", 2);
		ft_putstr_fd("Try: ./server", 1);
		exit (1);
	}

	if (type == SIZE)
	{
		ft_putstr_fd("\033{91mError; incorrect argument size", 2);
		exit(1);
	}
}

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
