/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:53:24 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/30 14:06:59 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	is_only_one(t_info *info);
static int	is_full(t_info *info);

int	philo_life(t_info *info)
{
	if (info->num % 2 == 0)
		something_do(info->time_to_eat / 2);
	pthread_create(&info->thread, 0, servant_life, info);
	if (is_only_one(info))
		return (0);
	while (!is_full(info))
	{
		action_fork(info, TAKE);
		action_eat(info);
		action_fork(info, PUT);
		action_sleep(info);
		action_think(info);
	}
	pthread_detach(info->thread);
	return (0);
}

static int	is_full(t_info *info)
{
	int	full;

	sem_wait(info->main);
	full = info->i_am_full;
	sem_post(info->main);
	return (full);
}

int	born_philo(t_info *info)
{
	int			idx;
	pid_t		pid;

	idx = 0;
	info->start_time = get_time();
	info->last_eat_time = info->start_time;
	sem_wait(info->main);
	while (idx < info->headcount)
	{
		pid = fork();
		if (pid == 0)
		{
			info->num = idx + 1;
			philo_life(info);
			break ;
		}
		idx++;
	}
	sem_post(info->main);
	return (1);
}

static int	is_only_one(t_info *info)
{
	if (info->headcount == 1)
	{
		sem_wait(info->forks);
		print_action(info, FORKN);
		sem_wait(info->forks);
		return (1);
	}
	return (0);
}
