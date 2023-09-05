/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_get_line_height.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:43:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/20 11:19:05 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static void	get_perp_wall_dist(t_info *info, t_ray *ray);

int	get_line_height(t_info *info, t_ray *ray)
{
	int	is_hit;

	is_hit = FALSE;
	while (!is_hit)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->hit[X] += ray->step[X];
			ray->side = X;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->hit[Y] += ray->step[Y];
			ray->side = Y;
		}
		if (info->map[ray->hit[Y]][ray->hit[X]] == '1')
			is_hit = TRUE;
	}
	get_perp_wall_dist(info, ray);
	return ((int)(HEIGHT / ray->perp_wall_dist));
}

static void	get_perp_wall_dist(t_info *info, t_ray *ray)
{
	if (ray->side == X)
	{
		ray->perp_wall_dist = (ray->hit[X] - info->player.pos[X]
				+ (1 - ray->step[X]) / 2) / ray->ray_dir[X];
	}
	else
	{
		ray->perp_wall_dist = (ray->hit[Y] - info->player.pos[Y]
				+ (1 - ray->step[Y]) / 2) / ray->ray_dir[Y];
	}
}
