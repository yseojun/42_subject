/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:15:35 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/06 19:57:20 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BONUS_H
# define DRAW_BONUS_H

# include "info_bonus.h"
# include <math.h>

typedef struct s_drline
{
	double	dx;
	double	dy;
	double	add;
}	t_drline;

int		image_pixel_put(t_map *map, int x, int y, int color);
int		make_color(int r, int g, int b);
void	draw_all(t_map *map, t_draw **draw);
void	draw_line(t_map *map, t_draw from, t_draw to);
void	draw_black(t_map *map);

void	set_rgb(t_drline *drline, t_draw from, t_draw to);
void	gradually(t_drline *drline, t_draw *from);

#endif