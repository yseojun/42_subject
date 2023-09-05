/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:07:27 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/07 11:33:19 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	set_step_side_dist(t_info *info, t_ray *ray);

t_ray	set_ray(t_info *info, int x)
{
	t_ray	ray;
	double	cam_x;

	cam_x = 2 * x / (double)WIDTH - 1;
	ray.ray_dir[X] = info->player.dir[X] + info->player.plane[X] * cam_x;
	ray.ray_dir[Y] = info->player.dir[Y] + info->player.plane[Y] * cam_x;
	ray.hit[X] = (int)info->player.pos[X];
	ray.hit[Y] = (int)info->player.pos[Y];
	ray.delta_dist[X] = fabs(1 / ray.ray_dir[X]);
	ray.delta_dist[Y] = fabs(1 / ray.ray_dir[Y]);
	set_step_side_dist(info, &ray);
	ray.is_door = FALSE;
	return (ray);
}

static void	set_step_side_dist(t_info *info, t_ray *ray)
{
	if (ray->ray_dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (info->player.pos[X] - ray->hit[X])
			* ray->delta_dist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = (ray->hit[X] + 1.0 - info->player.pos[X])
			* ray->delta_dist[X];
	}
	if (ray->ray_dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (info->player.pos[Y] - ray->hit[Y])
			* ray->delta_dist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = (ray->hit[Y] + 1.0 - info->player.pos[Y])
			* ray->delta_dist[Y];
	}
}
