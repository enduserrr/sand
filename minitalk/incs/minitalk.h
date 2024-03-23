/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:35:51 by asalo             #+#    #+#             */
/*   Updated: 2024/03/23 09:46:00 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK 
# define MINITALK

/**
 * @brief		Fork likely not to be used and instead of fork
 * 				copy the parent giving it a new pid in the process.
*/

/**
 * @attention	Get to know: kill, sleep, usleep, pause, getpid
 * 				signal, siemptyset, sigaddset, sigaction
 * 				(UNIX signal which behaviour can be mimiced in C).
*/

typedef enum
{
	CLEAN_EXIT,
	CLIENT_INPUT,
	SERVER_INPUT,
	SIZE
}	e_type;

# include <signal.h>
# include <sys/types.h>
# include <unistd.h> /*getppid, */
# include <stdio.h>
# include <limits.h>
# include <stdlib.h> /*exit*/
# include <sys/proc.h> /*PID_MAX*/
# include "libft/incs/libft.h"

void		bit_sender(int pid, char i);
void		signalhandler(int sig);

#endif