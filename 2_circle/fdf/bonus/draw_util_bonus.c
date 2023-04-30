/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:01:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/09 13:55:03 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_bonus.h"

int	make_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	set_rgb(t_drline *drline, t_draw from, t_draw to)
{
	drline->dx = to.x - from.x;
	drline->dy = to.y - from.y;
	drline->add = fabs(drline->dx);
	if (drline->add < fabs(drline->dy))
		drline->add = fabs(drline->dy);
}

void	gradually(t_drline *drline, t_draw *from)
{
	from->x += drline->dx / drline->add;
	from->y += drline->dy / drline->add;
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
