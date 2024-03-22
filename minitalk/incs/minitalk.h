/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:35:51 by asalo             #+#    #+#             */
/*   Updated: 2024/03/22 10:09:44 by asalo            ###   ########.fr       */
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

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define SIG1 44
# define SIG2 45

void	signalhandler(int sig);

#endif