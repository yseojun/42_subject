/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:02:36 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/09 14:09:32 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_bonus.h"

int	image_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x <= 2499) && (0 <= y && y <= 1199))
	{
		dst = map->img.addr + y * map->img.line_length
			+ x * (map->img.bits_per_pixel / 8);
		*(unsigned int *)dst = color;
		return (1);
	}
	else
		return (0);
}

void	draw_all(t_map *map, t_draw **draw)
{
	int	width;
	int	height;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			if (width + 1 < map->width)
				draw_line(map, draw[height][width], draw[height][width + 1]);
			if (height + 1 < map->height)
				draw_line(map, draw[height][width], draw[height + 1][width]);
			width++;
		}
		height++;
	}
}

void	draw_line(t_map *map, t_draw from, t_draw to)
{
	t_drline	drline;
	int			i;
	int			color;

	color = from.color;
	set_rgb(&drline, from, to);
	image_pixel_put(map, round(from.x), round(from.y), color);
	i = 0;
	while (i <= drline.add)
	{
		gradually(&drline, &from);
		if (i > drline.add / 2)
			color = to.color;
		if (image_pixel_put(map, round(from.x), round(from.y), color) == 0)
			break ;
		i++;
	}
}

void	draw_line_black(t_map *map, t_draw from, t_draw to)
{
	t_drline	drline;
	int			i;

	set_rgb(&drline, from, to);
	image_pixel_put(map, round(from.x), round(from.y), 0);
	i = 0;
	while (i <= drline.add)
	{
		gradually(&drline, &from);
		if (image_pixel_put(map, round(from.x), round(from.y), 0) == 0)
			break ;
		i++;
	}
}

void	draw_black(t_map *map)
{
	int	width;
	int	height;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			if (width + 1 < map->width)
				draw_line_black(map, \
				map->draw[height][width], map->draw[height][width + 1]);
			if (height + 1 < map->height)
				draw_line_black(map, \
				map->draw[height][width], map->draw[height + 1][width]);
			width++;
		}
		height++;
	}
}
