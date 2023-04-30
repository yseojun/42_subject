/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:41:22 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/28 21:06:45 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	philo_atoi(const char *str);
static int	is_invalid_av(int ac, char **av);
static int	make_fork(t_info *info);

int	init_info(t_info *info, int ac, char **av)
{
	if (is_invalid_av(ac, av))
		return (FAIL);
	info->headcount = philo_atoi(av[1]);
	info->time_to_die = philo_atoi(av[2]);
	info->time_to_eat = philo_atoi(av[3]);
	info->time_to_sleep = philo_atoi(av[4]);
	if (av[5])
		info->must_eat = philo_atoi(av[5]);
	else
		info->must_eat = 0;
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->main, NULL);
	info->someone_died = 0;
	if (make_fork(info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	make_fork(t_info *info)
{
	int	idx;

	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->headcount);
	if (info->forks == NULL)
		return (FAIL);
	idx = 0;
	while (idx < info->headcount)
	{
		if (pthread_mutex_init(&info->forks[idx++], NULL))
			return (FAIL);
	}
	return (SUCCESS);
}

static int	philo_atoi(const char *str)
{
	long long	ans;

	ans = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		return (0);
	if (*str == '+')
		str++;
	while (*str)
	{
		if ('0' > *str && *str > '9')
			return (0);
		ans = ans * 10 + *str - '0';
		str++;
	}
	return (ans);
}

static int	is_invalid_av(int ac, char **av)
{
	int	idx;

	if (ac < 5 || ac > 6)
		return (1);
	idx = 1;
	while (av[idx])
	{
		if (philo_atoi(av[idx]) == 0)
			return (FAIL);
		idx++;
	}
	return (SUCCESS);
}
