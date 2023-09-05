/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:08:46 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/07 16:10:23 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	chk_move(t_info *info, double dpos_x, double dpos_y);

void	move_up(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = info->player.dir[X] * val;
	dpos_y = info->player.dir[Y] * val;
	chk_move(info, dpos_x, dpos_y);
}

void	move_down(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = -info->player.dir[X] * val;
	dpos_y = -info->player.dir[Y] * val;
	chk_move(info, dpos_x, dpos_y);
}

void	move_left(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = info->player.dir[Y] * val;
	dpos_y = -info->player.dir[X] * val;
	chk_move(info, dpos_x, dpos_y);
}

void	move_right(t_info *info, double val)
{
	double	dpos_x;
	double	dpos_y;

	dpos_x = -info->player.dir[Y] * val;
	dpos_y = info->player.dir[X] * val;
	chk_move(info, dpos_x, dpos_y);
}

static void	chk_move(t_info *info, double dpos_x, double dpos_y)
{
	char	target_x;
	char	target_y;

	target_x = info->map[(int)info->player.pos[Y]] \
		[(int)(info->player.pos[X] + dpos_x * SPEED * 5)];
	target_y = info->map[(int)(info->player.pos[Y] + dpos_y * SPEED * 5)] \
		[(int)info->player.pos[X]];
	if (target_x == '0' || target_x == 'O')
		info->player.pos[X] += dpos_x * SPEED;
	if (target_y == '0' || target_y == 'O')
		info->player.pos[Y] += dpos_y * SPEED;
}
