/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:00:53 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/30 14:10:23 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	print_action(t_info *info, int action)
{
	sem_wait(info->main);
	print_line(info, action);
	if (action != DIEN)
		sem_post(info->main);
}

void	action_eat(t_info *info)
{
	print_action(info, EATN);
	sem_wait(info->main);
	info->last_eat_time = get_time();
	sem_post(info->main);
	something_do(info->time_to_eat);
	info->eat_count++;
	if (info->eat_count == info->must_eat)
	{
		sem_wait(info->main);
		info->i_am_full = 1;
		sem_post(info->main);
	}
}

void	action_fork(t_info *info, int take)
{
	if (take == TAKE)
	{
		sem_wait(info->forks);
		print_action(info, FORKN);
		sem_wait(info->forks);
		print_action(info, FORKN);
	}
	else
	{
		sem_post(info->forks);
		sem_post(info->forks);
	}
}

void	action_sleep(t_info *info)
{
	print_action(info, SLEEPN);
	something_do(info->time_to_sleep);
}

void	action_think(t_info *info)
{
	print_action(info, THINKN);
}
