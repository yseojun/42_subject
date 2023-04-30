/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:55:17 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/28 21:04:13 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo(t_philo **group, t_info *info)
{
	int		idx;

	*group = (t_philo *)malloc(sizeof(t_philo) * info->headcount);
	if (!group)
		return (FAIL);
	idx = 0;
	while (idx < info->headcount)
	{
		(*group)[idx].num = idx + 1;
		(*group)[idx].left_fork = &info->forks[idx];
		(*group)[idx].right_fork = &info->forks[(idx + 1) % info->headcount];
		(*group)[idx].eat_count = 0;
		(*group)[idx].i_am_full = 0;
		(*group)[idx].info = info;
		pthread_mutex_init(&(*group)[idx].full, NULL);
		pthread_mutex_init(&(*group)[idx].eat_time, NULL);
		idx++;
	}
	return (SUCCESS);
}
