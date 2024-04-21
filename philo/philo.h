/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:47:10 by asalo             #+#    #+#             */
/*   Updated: 2024/04/21 14:38:37 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>


# define ALLOC_ERR1 "ALLOC ERROR: THREAD ID"
# define ALLOC_ERR2 "ALLOC ERROR: PHILO"
# define ALLOC_ERR3 "ALLOC ERROR: FORK"

# define INPUT_ERR1 "INPUT ERROR: FORMAT"
# define INPUT_ERR2 "INPUT ERROR: COUNT"

# define THREAD_ERR1 "THREAD ERROR: INIT"
# define THREAD_ERR2 "THREAD ERROR: JOIN"
# define THREAD_ERR3 "THREAD ERROR: FORK INIT"

# define TIME_ERR "ERROR: SYSTEM TIME"

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

/**
 * @brief	Should I use one linked listed instead
*/

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;/*basicly where philo struct concurrently exists*/
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

int			check_input(int ac, char **av);
int			init(t_data *data, char **argv, int argc);
void		*routine(void *philo_pointer);
int			thread_init(t_data *data);
int			error(char *str, t_data *data);
u_int64_t	get_time(void);
void		messages(char *s, t_philo *philo);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		eat(t_philo *philo);
int			compare(char *s1, char *s2);

void		clear_data(t_data *data);
void		init_exit(t_data *data);

#endif
