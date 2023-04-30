/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servant_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:32:06 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/30 19:08:47 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	chk_die(t_philo *philo);
static int	is_someone_died(t_info *info);
static int	is_all_full(t_philo *philo, t_info *info);
static void	kill_all_philo(t_philo *philo, t_info *info);

void	servant_life(t_philo *philo, t_info *info)
{
	int	idx;

	while (!is_someone_died(info) && !is_all_full(philo, info))
	{
		idx = 0;
		while (idx < info->headcount && !is_someone_died(info))
		{
			if (chk_die(&philo[idx++]))
				break ;
		}
		usleep(100);
	}
	kill_all_philo(philo, info);
}

static int	chk_die(t_philo *philo)
{
	long long	hungry_time;

	pthread_mutex_lock(&philo->eat_time);
	hungry_time = get_dt(philo->last_eat_time);
	pthread_mutex_unlock(&philo->eat_time);
	if (hungry_time > philo->info->time_to_die)
	{
		pthread_mutex_lock(&philo->info->main);
		philo->info->someone_died = 1;
		pthread_mutex_unlock(&philo->info->main);
		print_action(philo, DIEN);
		return (1);
	}
	return (0);
}

static int	is_all_full(t_philo *philo, t_info *info)
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (idx < info->headcount)
	{
		pthread_mutex_lock(&philo[idx].full);
		count += philo[idx].i_am_full;
		pthread_mutex_unlock(&philo[idx].full);
		idx++;
	}
	if (count == info->headcount)
		return (1);
	return (0);
}

static int	is_someone_died(t_info *info)
{
	int	status;

	pthread_mutex_lock(&info->main);
	status = info->someone_died;
	pthread_mutex_unlock(&info->main);
	return (status);
}

static void	kill_all_philo(t_philo *philo, t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->headcount)
		pthread_join(philo[idx++].thread, NULL);
}
