/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:45:14 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/28 20:23:10 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;

	if (init_info(&info, ac, av) == SUCCESS
		&& init_philo(&philo, &info) == SUCCESS)
	{
		born_philo(philo, &info);
		servant_life(philo, &info);
		free(info.forks);
		free(philo);
	}
	return (0);
}
