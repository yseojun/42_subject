/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:01:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/06 18:22:09 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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
