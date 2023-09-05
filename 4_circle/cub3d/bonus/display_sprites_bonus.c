/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:36:50 by rolee             #+#    #+#             */
/*   Updated: 2023/07/20 14:16:15 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static void	get_sprite_distance(t_info *info);
static void	sort_sprites(t_info *info);
static void	calculate_sprite(t_info *info, t_spr_info *spr, int i);
static void	calculrate_sprite_draw(t_spr_info *spr);

void	display_sprites(t_info *info)
{
	t_spr_info	spr;
	int			i;

	get_sprite_distance(info);
	sort_sprites(info);
	i = 0;
	while (i < info->sprite_cnt)
	{
		calculate_sprite(info, &spr, i);
		calculrate_sprite_draw(&spr);
		display_each_sprite(info, spr);
		i++;
	}
}

static void	calculate_sprite(t_info *info, t_spr_info *spr, int i)
{
	spr->each = &info->sprites[i];
	spr->sprite[X] = spr->each->pos[X] - info->player.pos[X];
	spr->sprite[Y] = spr->each->pos[Y] - info->player.pos[Y];
	spr->inv_det = 1.0 / (info->player.plane[X] * info->player.dir[Y]
			- info->player.plane[Y] * info->player.dir[X]);
	spr->transform[X] = spr->inv_det * (info->player.dir[Y] * spr->sprite[X]
			- info->player.dir[X] * spr->sprite[Y]);
	spr->transform[Y] = spr->inv_det * (info->player.plane[X] * spr->sprite[Y]
			- info->player.plane[Y] * spr->sprite[X]);
	spr->v_move_screen = (int)(spr->each->v_move / spr->transform[Y]);
	spr->sprite_screen_x = (int)((WIDTH / 2)
			* (1 + spr->transform[X] / spr->transform[Y]));
	spr->sprite_height = abs((int)(HEIGHT / spr->transform[Y]))
		/ spr->each->v_div;
	spr->sprite_width = abs((int)(HEIGHT / spr->transform[Y]))
		/ spr->each->u_div;
}

static void	calculrate_sprite_draw(t_spr_info *spr)
{
	spr->drawstart[Y] = -spr->sprite_height / 2 + HEIGHT / 2
		+ spr->v_move_screen;
	if (spr->drawstart[Y] < 0)
		spr->drawstart[Y] = 0;
	spr->drawend[Y] = spr->sprite_height / 2 + HEIGHT / 2 + spr->v_move_screen;
	if (spr->drawend[Y] >= HEIGHT)
		spr->drawend[Y] = HEIGHT - 1;
	spr->drawstart[X] = -spr->sprite_width / 2 + spr->sprite_screen_x;
	if (spr->drawstart[X] < 0)
		spr->drawstart[X] = 0;
	spr->drawend[X] = spr->sprite_width / 2 + spr->sprite_screen_x;
	if (spr->drawend[X] >= WIDTH)
		spr->drawend[X] = WIDTH - 1;
}

static void	get_sprite_distance(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->sprite_cnt)
	{
		info->sprites[idx].distance = get_distance(
				info->player.pos[X], info->player.pos[Y],
				info->sprites[idx].pos[X], info->sprites[idx].pos[Y]);
		idx++;
	}
}

static void	sort_sprites(t_info *info)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < info->sprite_cnt - 1)
	{
		j = 0;
		while (j < info->sprite_cnt - 1 - i)
		{
			if (info->sprites[j].distance < info->sprites[j + 1].distance)
			{
				temp = info->sprites[j];
				info->sprites[j] = info->sprites[j + 1];
				info->sprites[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
