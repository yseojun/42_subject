/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:23 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/20 11:17:50 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static int	press_key(int keycode, t_info *info);
static int	release_key(int keycode, t_info *info);
static int	no_event(t_info *info);

void	manage_event(t_info *info)
{
	mlx_hook(info->win, KEY_PRESS, 0, &press_key, info);
	mlx_hook(info->win, KEY_RELEASE, 0, &release_key, info);
	mlx_hook(info->win, CLOSE_BUTTON, 0, &finish_game, info);
	mlx_loop_hook(info->mlx, &no_event, info);
}

static int	press_key(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		info->ev.push_w = TRUE;
	if (keycode == KEY_A)
		info->ev.push_a = TRUE;
	if (keycode == KEY_S)
		info->ev.push_s = TRUE;
	if (keycode == KEY_D)
		info->ev.push_d = TRUE;
	if (keycode == KEY_LEFT_ARROW)
		info->ev.push_left = TRUE;
	if (keycode == KEY_RIGHT_ARROW)
		info->ev.push_right = TRUE;
	if (keycode == KEY_ESC)
		finish_game(info);
	return (SUCCESS);
}

static int	release_key(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		info->ev.push_w = FALSE;
	if (keycode == KEY_A)
		info->ev.push_a = FALSE;
	if (keycode == KEY_S)
		info->ev.push_s = FALSE;
	if (keycode == KEY_D)
		info->ev.push_d = FALSE;
	if (keycode == KEY_LEFT_ARROW)
		info->ev.push_left = FALSE;
	if (keycode == KEY_RIGHT_ARROW)
		info->ev.push_right = FALSE;
	return (SUCCESS);
}

static int	no_event(t_info *info)
{
	if ((info->ev.push_a && info->ev.push_w)
		|| (info->ev.push_d && info->ev.push_w)
		|| (info->ev.push_a && info->ev.push_s)
		|| (info->ev.push_d && info->ev.push_s))
		move(info, 0.5);
	else if (info->ev.push_a || info->ev.push_w
		|| info->ev.push_d || info->ev.push_s)
		move(info, 1);
	if (info->ev.push_left)
		rotate(info, -1, 0.1);
	else if (info->ev.push_right)
		rotate(info, 1, 0.1);
	display_world(info);
	return (SUCCESS);
}
