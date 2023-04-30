/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:37:29 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/30 14:47:06 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
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
	sem_t			*forks;
	sem_t			*main;
	int				num;
	int				headcount;
	int				eat_count;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		must_eat;
	long long		start_time;
	long long		last_eat_time;
	pthread_t		thread;
	int				i_am_full;
}				t_info;

// init_info.c
int			init_info(t_info *info, int ac, char **av);

// born_philo.c
int			born_philo(t_info *info);

// servant_life.c
void		*servant_life(void *data);
void		kill_all_philo(t_info *info);

// action.c
void		print_action(t_info *info, int action);
void		action_eat(t_info *info);
void		action_fork(t_info *info, int take);
void		action_sleep(t_info *info);
void		action_think(t_info *info);

// time.c
long long	get_time(void);
long long	get_dt(long long time);
void		something_do(long long time);

// util.c
void		print_line(t_info *info, int action);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif