/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:36:40 by asalo             #+#    #+#             */
/*   Updated: 2024/03/22 10:10:27 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/minitalk.h"

void	error_exit(void)
{
	write(2, "Error: incorrect input\n",23);
	exit (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		error_exit();
	while (i < argc)
	{
		ft_atol(argv[i]);
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i] < INT_MIN))
			error_exit();
	}
		

}

// int	main(void)
// {

// 	printf("PID: %d\n", getpid());
// 	/*	Overload signal handlers	*/
// 	signal(SIG1, signalhandler);
// 	signal(SIG2, signalhandler);
// 	printf("Waiting, waiting and waiting...\n");
// 	/*	Start an endless loop	*/
// 	while (1)
// 		sleep(1);
// 	return (0);
// }
