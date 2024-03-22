/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:37:28 by asalo             #+#    #+#             */
/*   Updated: 2024/03/22 17:09:43 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	signalhandler(int sig)
{
	static int	bit;
	int			i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		str_to_fd(i, 1);
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
	str_to_fd("\033[94mPID\033[0m \033[96m->\033[0m %d\n", 1);
	str_to_fd("\033[90mWaiting for a message...\033[0m\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, signalhandler);
		signal(SIGUSR2, signalhandler);
		pause();
	}
	return (0);
}
