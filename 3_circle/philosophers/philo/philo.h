/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:37:29 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/28 21:37:40 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIE "died\n"
# define FORK "has taken a fork\n"
# define DIEN 0
# define EATN 1
# define SLEEPN 2
# define THINKN 3
# define FORKN 4
# define TAKE 1
# define PUT 0
# define SUCCESS 0
# define FAIL 1

typedef struct s_info
{
	int				headcount;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		must_eat;
	long long		start_time;
	int				someone_died;
	pthread_mutex_t	print;
	pthread_mutex_t	main;
	pthread_mutex_t	*forks;
}				t_info;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	full;
	pthread_mutex_t	eat_time;
	int				num;
	int				eat_count;
	long long		last_eat_time;
	int				i_am_full;
	t_info			*info;
}				t_philo;

// init_info.c
int			init_info(t_info *info, int ac, char **av);

// init_philo.c
int			init_philo(t_philo **group, t_info *info);

// philo_life.c
int			born_philo(t_philo *philo, t_info *info);
void		*philo_life(void *data);

// time.c
long long	get_time(void);
void		set_time(t_philo *philo, t_info *info);
long long	get_dt(long long time);
void		something_do(long long time);

// action.c
void		print_action(t_philo *philo, int action);
void		action_eat(t_philo *philo);
void		action_fork(t_philo *philo, int take);
void		action_sleep(t_philo *philo);
void		action_think(t_philo *philo);

// servant_life.c
void		servant_life(t_philo *philo, t_info *info);

// util.c
void		print_line(t_philo *philo, int action);

#endif