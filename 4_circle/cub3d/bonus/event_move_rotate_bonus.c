/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:11:41 by rolee             #+#    #+#             */
/*   Updated: 2023/07/07 16:18:56 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

void	move(t_info *info, double val)
{
	if (info->ev.push_w)
		move_up(info, val);
	if (info->ev.push_s)
		move_down(info, val);
	if (info->ev.push_a)
		move_left(info, val);
	if (info->ev.push_d)
		move_right(info, val);
}

void	rotate(t_info *info, int sign, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->player.dir[X];
	old_plane_x = info->player.plane[X];
	info->player.dir[X] = info->player.dir[X] * cos(angle * sign)
		- info->player.dir[Y] * sin(angle * sign);
	info->player.dir[Y] = old_dir_x * sin(angle * sign)
		+ info->player.dir[Y] * cos(angle * sign);
	info->player.plane[X] = info->player.plane[X] * cos(angle * sign)
		- info->player.plane[Y] * sin(angle * sign);
	info->player.plane[Y] = old_plane_x * sin(angle * sign)
		+ info->player.plane[Y] * cos(angle * sign);
}

int	mouse_move(int x, int y, t_info *info)
{
	y = 0;
	info->ev.mouse_dx = x - info->ev.prev_mouse_x;
	if (info->ev.mouse_dx == 0)
		return (0);
	else if (info->ev.mouse_dx < 0)
		rotate(info, 1, info->ev.mouse_dx * 0.001);
	else
		rotate(info, 1, info->ev.mouse_dx * 0.001);
	mlx_mouse_move(info->win, WIDTH / 2, HEIGHT / 2);
	info->ev.prev_mouse_x = WIDTH / 2;
	return (SUCCESS);
}
