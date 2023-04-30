/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servant_life_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:32:06 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/30 14:10:13 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	chk_master_done(t_info *info);

void	*servant_life(void *data)
{
	t_info	*info;

	info = data;
	while (1)
		chk_master_done(info);
	return (0);
}

static int	chk_master_done(t_info *info)
{
	long long	hungry_time;
	int			is_full;

	sem_wait(info->main);
	hungry_time = get_dt(info->last_eat_time);
	is_full = info->i_am_full;
	sem_post(info->main);
	if (is_full == 1)
		exit(0);
	if (hungry_time > info->time_to_die)
	{
		print_action(info, DIEN);
		exit(1);
	}
	usleep(100);
	return (0);
}

void	kill_all_philo(t_info *info)
{
	int	idx;
	int	status;

	idx = 0;
	while (idx < info->headcount)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			kill(0, SIGINT);
			sem_post(info->main);
		}
		idx++;
	}
	sem_close(info->main);
	sem_close(info->forks);
}
