/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:37:28 by asalo             #+#    #+#             */
/*   Updated: 2024/03/23 13:57:34 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

static void	error_exit(e_type type)
{
	if (type == CLEAN_EXIT)
		exit(0);
	if (type == CLIENT_INPUT)
	{
		ft_putstr_fd("Error: incorrect format.\n", 2);
		ft_putstr_fd("Try: ./client <PID> <MESSAGE>\n", 1);
		ft_putstr_fd("(if server isn't initialised, first run the following commnd:\n", 1);
		ft_putstr_fd("-> ./server\n", 1);
		exit(1);
	}
	if (type == SERVER_INPUT)
	{
		ft_putstr_fd("Error: incorrect format.", 2);
		ft_putstr_fd("Try: ./server", 1);
		exit (1);
	}

	if (type == SIZE)
	{
		ft_putstr_fd("91mError: incorrect argument size", 2);
		exit (1);
	}
}

void	signalhandler(int sig)
{
	static int	bit;
	static int	i;
	// void		*k;

	// k = sig;
	// if ((int)k == SIGUSR1)
	if (sig == SIGUSR1)
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
	pid_t	pid;

	(void)argv;
	if (argc != 1)
		error_exit(SERVER_INPUT);
	pid = getpid();
	if (pid > INT_MAX || pid < 0)
	ft_putstr_fd("-> ", 1);
	ft_putstr_fd(ft_itoa(pid), 1);
	ft_putstr_fd("\nWaiting for a message...\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, signalhandler);
		signal(SIGUSR2, signalhandler);
		pause();
	}
	return (0);
}