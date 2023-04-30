/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:41:22 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/30 14:46:30 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	philo_atoi(const char *str);
static int	is_invalid_av(int ac, char **av);

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
	info->eat_count = 0;
	info->i_am_full = 0;
	sem_unlink("forks");
	sem_unlink("main");
	info->forks = sem_open("forks", O_CREAT, 0644, info->headcount);
	info->main = sem_open("main", O_CREAT, 0644, 1);
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
