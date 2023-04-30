/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:54:28 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/09 14:21:44 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"
#include "hook_bonus.h"

void	_move(t_map *map, t_draw **draw, int keycode)
{
	int	move_x;
	int	move_y;
	int	height;
	int	width;

	move_x = 0;
	move_y = 0;
	if (keycode == 123 || keycode == 124)
		move_x = (2 * keycode - 247) * 100;
	if (keycode == 125 || keycode == 126)
		move_y = (251 - 2 * keycode) * 100;
	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			draw[height][width].x += move_x;
			draw[height][width].y += move_y;
			width++;
		}
		height++;
	}
	map->x_move += move_x;
	map->y_move += move_y;
}

void	_zoom(t_map *map, t_draw **draw, int keycode)
{
	double	in_or_out;
	double	center_to_x;
	double	center_to_y;
	int		height;
	int		width;

	in_or_out = ((51 - (double)keycode * 2) / 12);
	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			center_to_x = draw[height][width].x - 1250;
			center_to_y = draw[height][width].y - 600;
			draw[height][width].x += center_to_x * in_or_out;
			draw[height][width].y += center_to_y * in_or_out;
			width++;
		}
		height++;
	}
	map->x_move *= 1 + in_or_out;
	map->y_move *= 1 + in_or_out;
	map->magnitude *= 1 + in_or_out;
}

void	_refresh(t_map *map, t_draw **draw)
{
	int		height;
	int		width;

	height = 0;
	reset_min_max(map, draw);
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			draw[height][width].x = (draw[height][width].x
					- (map->x_max + map->x_min) / 2) + 1250;
			draw[height][width].y = (draw[height][width].y
					- (map->y_max + map->y_min) / 2) + 600;
			width++;
		}
		height++;
	}
	map->x_move = 0;
	map->y_move = 0;
}

void	_rotate(t_map *map, t_draw **draw, t_point **point)
{
	int		height;
	int		width;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			set_point(map, &point[height][width], height, width);
			draw[height][width].x = cos(map->degree) * map->magnitude
				* (point[height][width].x - point[height][width].y);
			draw[height][width].y = (sin(map->degree)
					* (point[height][width].x + point[height][width].y)
					- point[height][width].z) * map->magnitude;
			width++;
		}
		height++;
	}
	reset_min_max(map, draw);
	revise_draw_rotate(map, draw);
}

void	revise_draw_rotate(t_map *map, t_draw **draw)
{
	int		height;
	int		width;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			draw[height][width].x = (draw[height][width].x
					- (map->x_max + map->x_min) / 2)
				+ 1250 + map->x_move;
			draw[height][width].y = (draw[height][width].y
					- (map->y_max + map->y_min) / 2)
				+ 600 + map->y_move;
			width++;
		}
		height++;
	}
}
