/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:45:14 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/30 14:13:57 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	main(int ac, char **av)
{
	t_info		info;

	if (init_info(&info, ac, av) == SUCCESS)
	{
		born_philo(&info);
		kill_all_philo(&info);
	}
	return (0);
}
