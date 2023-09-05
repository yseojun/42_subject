/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:41:56 by rolee             #+#    #+#             */
/*   Updated: 2023/07/12 15:38:53 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

void	free_str_arr(char **str_arr)
{
	int	idx;

	if (!str_arr)
		return ;
	idx = 0;
	while (str_arr[idx])
		free(str_arr[idx++]);
	free(str_arr);
}

int	str_arr_len(char **str_arr)
{
	int	idx;

	if (!str_arr)
		return (FAILURE);
	idx = 0;
	while (str_arr[idx])
		idx++;
	return (idx);
}

double	get_distance(double from_x, double from_y, double to_x, double to_y)
{
	double	dist_x;
	double	dist_y;

	dist_x = to_x - from_x;
	dist_y = to_y - from_y;
	return (pow(dist_x, 2) + pow(dist_y, 2));
}

int	finish_game(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

int	occur_error(char *message)
{
	printf("ERROR: %s\n", message);
	return (EXIT_FAILURE);
}
