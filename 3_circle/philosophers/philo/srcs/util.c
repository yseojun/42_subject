/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:50:05 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/28 21:37:45 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static char	*get_action_str(int action)
{
	if (action == FORKN)
		return (FORK);
	else if (action == EATN)
		return (EAT);
	else if (action == SLEEPN)
		return (SLEEP);
	else if (action == THINKN)
		return (THINK);
	else
		return (DIE);
}

void	print_line(t_philo *philo, int action)
{
	printf("%lld %d %s", get_dt(philo->info->start_time), philo->num, \
		get_action_str(action));
}
