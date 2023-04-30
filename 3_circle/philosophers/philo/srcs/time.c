/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:21:13 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/28 20:20:18 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_time(t_philo *philo, t_info *info)
{
	int			idx;

	idx = 0;
	info->start_time = get_time();
	while (idx < info->headcount)
		philo[idx++].last_eat_time = info->start_time;
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	get_dt(long long time)
{
	return (get_time() - time);
}

void	something_do(long long time)
{
	long long	end;

	end = get_time() + time;
	while (get_time() < end)
		usleep(100);
}
