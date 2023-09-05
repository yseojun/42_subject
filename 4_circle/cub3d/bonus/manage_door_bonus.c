/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:10:02 by rolee             #+#    #+#             */
/*   Updated: 2023/07/10 18:04:20 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static int	is_min_distance_to_door(t_info *info, double *min, int ny, int nx);
static void	display_door(t_info	*info, int min_y, int min_x);

void	manage_door(t_info *info)
{
	const int	dxy[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
	int			nxy[2];
	double		min_distance;
	int			min_xy[2];
	int			i;

	min_distance = 1.5;
	i = 0;
	while (i < 4)
	{
		nxy[Y] = floor(info->player.pos[Y]) + dxy[Y][i];
		nxy[X] = floor(info->player.pos[X]) + dxy[X][i];
		if ((info->map[nxy[Y]][nxy[X]] == '2'
			|| info->map[nxy[Y]][nxy[X]] == 'O')
			&& is_min_distance_to_door(info, &min_distance, nxy[Y], nxy[X]))
		{
			min_xy[Y] = nxy[Y];
			min_xy[X] = nxy[X];
		}
		i++;
	}
	if (min_distance == 1.5)
		return ;
	display_door(info, min_xy[Y], min_xy[X]);
}

static int	is_min_distance_to_door(t_info *info, double *min, int ny, int nx)
{
	double	distance;

	distance = get_distance(info->player.pos[X], \
				info->player.pos[Y], nx + 0.5, ny + 0.5);
	if (distance < *min)
	{
		*min = distance;
		return (TRUE);
	}
	return (FALSE);
}

static void	display_door(t_info	*info, int min_y, int min_x)
{
	if (info->map[min_y][min_x] == '2')
		info->map[min_y][min_x] = 'O';
	else
		info->map[min_y][min_x] = '2';
	display_frame(info);
}
