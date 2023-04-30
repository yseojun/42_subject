/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:53:24 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/30 13:55:56 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_someone_died(t_philo *philo);
static int	is_only_one(t_philo *philo);

void	*philo_life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (is_only_one(philo))
		return (0);
	if (philo->num % 2 == 0)
		usleep(philo->info->time_to_eat * 500);
	while (is_someone_died(philo) == 0 && philo->i_am_full == 0)
	{
		action_fork(philo, TAKE);
		action_eat(philo);
		action_fork(philo, PUT);
		action_sleep(philo);
		action_think(philo);
	}
	return (0);
}

static int	is_someone_died(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->info->main);
	status = philo->info->someone_died;
	pthread_mutex_unlock(&philo->info->main);
	return (status);
}

int	born_philo(t_philo *philo, t_info *info)
{
	int	idx;

	idx = 0;
	pthread_mutex_lock(&info->main);
	while (idx < info->headcount)
	{
		pthread_create(&philo[idx].thread, NULL, philo_life, &philo[idx]);
		idx++;
	}
	set_time(philo, info);
	pthread_mutex_unlock(&info->main);
	return (1);
}

static int	is_only_one(t_philo *philo)
{
	if (philo->info->headcount == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, FORKN);
		return (1);
	}
	return (0);
}