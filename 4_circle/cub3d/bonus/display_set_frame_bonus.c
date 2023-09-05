/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_set_frame_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:27:47 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/11 14:31:15 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void			draw_x_frame(t_info *info, t_ray *ray, \
	int x, int line_height);
static int			get_tex_x(t_info *info, t_ray *ray);
static unsigned int	get_color(t_info *info, t_ray *ray, t_tex_info inf);
static int			get_directrion(t_ray *ray);

void	set_frame(t_info *info, t_ray *ray, int x, int line_height)
{
	ray->start = -line_height / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = line_height / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	ray->dir = get_directrion(ray);
	draw_x_frame(info, ray, x, line_height);
}

static int	get_directrion(t_ray *ray)
{
	if (ray->is_door)
		return (DOOR);
	if (ray->side == X)
	{
		if (ray->ray_dir[X] > 0)
			return (W);
		else
			return (E);
	}
	else
	{
		if (ray->ray_dir[Y] > 0)
			return (N);
		else
			return (S);
	}
}

static void	draw_x_frame(t_info *info, t_ray *ray, int x, int line_height)
{
	t_tex_info		t_inf;
	char			*dst;
	int				y;

	t_inf.step = 1.0 * info->texture[ray->dir].height / line_height;
	t_inf.tex_pos = (ray->start - HEIGHT / 2 + line_height / 2) * t_inf.step;
	t_inf.tex_x = get_tex_x(info, ray);
	t_inf.texture_int = (int *)info->texture[ray->dir].addr;
	y = ray->start;
	while (y < ray->end)
	{
		t_inf.tex_y = (int)t_inf.tex_pos & (info->texture[ray->dir].height - 1);
		t_inf.tex_pos += t_inf.step;
		dst = info->frame.addr + y * info->frame.line_length
			+ x * (info->frame.bits / 8);
		*(unsigned int *)dst = get_color(info, ray, t_inf);
		y++;
	}
}

static int	get_tex_x(t_info *info, t_ray *ray)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == X)
		wall_x = info->player.pos[Y] + ray->perp_wall_dist * ray->ray_dir[Y];
	else
		wall_x = info->player.pos[X] + ray->perp_wall_dist * ray->ray_dir[X];
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)info->texture[ray->dir].width);
	if (ray->side == X && ray->ray_dir[X] > 0)
		tex_x = info->texture[ray->dir].width - tex_x - 1;
	if (ray->side == Y && ray->ray_dir[Y] < 0)
		tex_x = info->texture[ray->dir].width - tex_x - 1;
	return (tex_x);
}

static unsigned int	get_color(t_info *info, t_ray *ray, t_tex_info inf)
{
	unsigned int	color;
	int				idx;

	idx = info->texture[ray->dir].height * inf.tex_y + inf.tex_x;
	color = inf.texture_int[idx];
	if (ray->side == Y)
		color = (color >> 1) & 8355711;
	return (color);
}
