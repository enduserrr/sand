/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:37:28 by asalo             #+#    #+#             */
/*   Updated: 2024/03/22 18:36:30 by asalo            ###   ########.fr       */
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

void	signalhandler(int sig)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putstr_fd(ft_itoa(i), 1);
		bit = 0;
		i = 0;
	}
}
/**
 * @brief	The function 'pause()' haults the calling process
 * 			until a signal is received.
*/

int	main(int argc, char **argv)
{
	int	pid;
	int	tmp;
	int	i;

	i = 0;
	if (argc != 1)
		error_exit(SERVER_INPUT);
	while (i < argc)
	{
		tmp = ft_atol(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			error_exit(SERVER_INPUT);
		i++;
	}
	pid = getpid();
	ft_putstr_fd("\033[94mPID\033[0m \033[96m->\033[0m %d\n", 1);
	ft_putstr_fd("\033[90mWaiting for a message...\033[0m\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, signalhandler);
		signal(SIGUSR2, signalhandler);
		pause();
	}
	return (0);
}
