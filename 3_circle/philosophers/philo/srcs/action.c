/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:00:53 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/28 20:19:54 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->info->print);
	pthread_mutex_lock(&philo->info->main);
	if (action == DIEN || !philo->info->someone_died)
		print_line(philo, action);
	pthread_mutex_unlock(&philo->info->main);
	pthread_mutex_unlock(&philo->info->print);
}

void	action_eat(t_philo *philo)
{
	print_action(philo, EATN);
	pthread_mutex_lock(&philo->eat_time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->eat_time);
	something_do(philo->info->time_to_eat);
	philo->eat_count++;
	if (philo->eat_count == philo->info->must_eat)
	{
		pthread_mutex_lock(&philo->full);
		philo->i_am_full = 1;
		pthread_mutex_unlock(&philo->full);
	}
}

void	action_fork(t_philo *philo, int take)
{
	if (take == TAKE)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, FORKN);
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, FORKN);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	action_sleep(t_philo *philo)
{
	print_action(philo, SLEEPN);
	something_do(philo->info->time_to_sleep);
}

void	action_think(t_philo *philo)
{
	print_action(philo, THINKN);
}
