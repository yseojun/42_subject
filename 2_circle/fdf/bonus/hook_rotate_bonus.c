/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:23:17 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/09 15:04:05 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_bonus.h"
#include "info_bonus.h"

void	rotate_xyz(t_map *map, t_point *point)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_y = point->y;
	prev_z = point->z;
	point->y = prev_y * cos(map->x_degree) + prev_z * sin(map->x_degree);
	point->z = -prev_y * sin(map->x_degree) + prev_z * cos(map->x_degree);
	prev_x = point->x;
	prev_z = point->z;
	point->x = prev_x * cos(map->y_degree) - prev_z * sin(map->y_degree);
	point->z = prev_x * sin(map->y_degree) + prev_z * cos(map->y_degree);
	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(map->z_degree) + prev_y * sin(map->z_degree);
	point->y = -prev_x * sin(map->z_degree) + prev_y * cos(map->z_degree);
}

void	set_point(t_map *map, t_point *point, int height, int width)
{
	point->x = width;
	point->y = height;
	point->z = map->value[height][width];
	rotate_xyz(map, point);
}

void	change_degree(t_map *map, int keycode)
{
	if (keycode == 6)
		map->z_degree += M_PI / 180;
	else if (keycode == 0)
		map->z_degree -= M_PI / 180;
	else if (keycode == 7)
		map->x_degree += M_PI / 180;
	else if (keycode == 1)
		map->x_degree -= M_PI / 180;
	else if (keycode == 8)
		map->y_degree += M_PI / 180;
	else if (keycode == 2)
		map->y_degree -= M_PI / 180;
}

void	conic_projection(t_map *map, t_draw **draw)
{
	map->degree = 0;
	map->x_degree = 0;
	map->y_degree = 0;
	map->z_degree = M_PI / 4;
	map->x_move = 0;
	map->y_move = 0;
	_rotate(map, draw, map->point);
}

void	reset_min_max(t_map *map, t_draw **draw)
{
	int		height;
	int		width;

	map->x_max = draw[0][0].x;
	map->x_min = draw[0][0].x;
	map->y_max = draw[0][0].y;
	map->y_min = draw[0][0].y;
	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			update_size(map, draw[height][width].y, draw[height][width].x);
			width++;
		}
		height++;
	}
}
