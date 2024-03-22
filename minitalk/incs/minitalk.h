/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:35:51 by asalo             #+#    #+#             */
/*   Updated: 2024/03/22 16:09:27 by asalo            ###   ########.fr       */
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
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define SIG1 44
# define SIG2 45

/* UTILS */
void		str_to_fd(char *s, int fd);
void		error_exit(e_type type);
long		ft_atol(const char *str);

/* CLIENT */
void		bit_sender(int pid, char i);

/* SERVER */

#endif