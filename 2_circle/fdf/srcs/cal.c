/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:53:38 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/09 15:12:12 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

void	cal_draw(t_map *map, t_draw **draw)
{
	int	height;
	int	width;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			draw[height][width].x = (width - height) * cos(map->degree);
			draw[height][width].y = (width + height) * sin(map->degree)
				- map->value[height][width];
			if (map->is_color == 0)
				draw[height][width].color = value_to_color(map, height, width);
			update_size(map, draw[height][width].y, draw[height][width].x);
			width++;
		}
		height++;
	}
	revise_draw(map, draw);
}

void	revise_draw(t_map *map, t_draw **draw)
{
	int		height;
	int		width;

	map->magnitude = set_magnitude(map);
	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			draw[height][width].x = (draw[height][width].x
					- (map->x_max + map->x_min) / 2) * map->magnitude + 1250;
			draw[height][width].y = (draw[height][width].y
					- (map->y_max + map->y_min) / 2) * map->magnitude + 600;
			width++;
		}
		height++;
	}
}

int	set_magnitude(t_map *map)
{
	int		magnitude;
	double	dx;
	double	dy;

	magnitude = 1;
	dx = map->x_max - map->x_min;
	dy = map->y_max - map->y_min;
	while (dx * magnitude < 1200 && dy * magnitude < 600)
		magnitude++;
	return (magnitude);
}

void	update_size(t_map *map, double y, double x)
{
	if (map->x_max < x)
		map->x_max = x;
	if (map->x_min > x)
		map->x_min = x;
	if (map->y_max < y)
		map->y_max = y;
	if (map->y_min > y)
		map->y_min = y;
}

int	value_to_color(t_map *map, int height, int width)
{
	int	r;
	int	g;
	int	b;
	int	range;

	range = map->max - map->min;
	if (range == 0)
		return (0x00ffffff);
	r = 255;
	g = (map->max - map->value[height][width]) / range * 255;
	b = (map->max - map->value[height][width]) / range * 255;
	return ((r << 16) + (g << 8) + b);
}
