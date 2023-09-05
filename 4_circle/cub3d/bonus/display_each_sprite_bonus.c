/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_each_sprite_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:17:01 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/20 14:28:06 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static int	get_sprite_tex_x(t_spr_info spr, int x);
static void	put_sprite_color_to_frame(t_info *info, int color, int x, int y);
static void	draw_sprite_y(t_info *info, t_spr_info spr, int x, int tex_x);
static int	get_sprite_color(t_spr_info spr, int tex_x, int tex_y);

void	display_each_sprite(t_info *info, t_spr_info spr)
{
	int		x;
	int		tex_x;

	x = spr.drawstart[X];
	while (x < spr.drawend[X])
	{
		if (spr.transform[Y] > 0 && x > 0 && x < WIDTH
			&& spr.transform[Y] < info->z_buffer[x])
		{
			tex_x = get_sprite_tex_x(spr, x);
			draw_sprite_y(info, spr, x, tex_x);
		}
		x++;
	}
}

static int	get_sprite_tex_x(t_spr_info spr, int x)
{
	int	tex_x;

	tex_x = (int)(256 * (x - (-spr.sprite_width / 2 + spr.sprite_screen_x))
			* spr.each->frame->width / spr.sprite_width) / 256;
	return (tex_x);
}

static void	draw_sprite_y(t_info *info, t_spr_info spr, int x, int tex_x)
{
	int	y;
	int	d;
	int	tex_y;
	int	color;

	y = spr.drawstart[Y];
	while (y < spr.drawend[Y])
	{
		d = (y - spr.v_move_screen) * 256
			- HEIGHT * 128 + spr.sprite_height * 128;
		tex_y = ((d * spr.each->frame->height) / spr.sprite_height)
			/ 256;
		color = get_sprite_color(spr, tex_x, tex_y);
		if ((color & 0x00FFFFFF) != 0)
			put_sprite_color_to_frame(info, color, x, y);
		y++;
	}
}

static int	get_sprite_color(t_spr_info spr, int tex_x, int tex_y)
{
	int	texture_width;
	int	color;
	int	*tx;

	texture_width = spr.each->frame[spr.each->idx].width;
	tx = (int *)spr.each->frame[spr.each->idx].addr;
	color = tx[tex_y * texture_width + tex_x];
	return (color);
}

static void	put_sprite_color_to_frame(t_info *info, int color, int x, int y)
{
	int		*tx;

	tx = (int *)info->frame.addr;
	tx[y * WIDTH + x] = color;
}
