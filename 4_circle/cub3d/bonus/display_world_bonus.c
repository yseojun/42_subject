/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_world_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:25:08 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/12 15:04:11 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	display_background(t_info *info);

void	display_world(t_info *info)
{
	t_ray	ray;
	int		x;
	int		line_height;

	x = 0;
	display_background(info);
	while (x < WIDTH)
	{
		ray = set_ray(info, x);
		line_height = get_line_height(info, &ray);
		set_frame(info, &ray, x, line_height);
		info->z_buffer[x] = ray.perp_wall_dist;
		x++;
	}
}

static void	display_background(t_info *info)
{
	int	i;
	int	j;
	int	*tx;

	tx = (int *)info->frame.addr;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				tx[i * WIDTH + j] = encode_rgb(info->c_color);
			else
				tx[i * WIDTH + j] = encode_rgb(info->f_color);
			j++;
		}
		i++;
	}
}
