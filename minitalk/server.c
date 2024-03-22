/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:37:28 by asalo             #+#    #+#             */
/*   Updated: 2024/03/22 09:59:49 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/minitalk.h"

void	bit_ops(int pid, char i)
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
void	signalhandler(int sig)
{
	printf("Received a signal with number: %d\n", sig);
}
