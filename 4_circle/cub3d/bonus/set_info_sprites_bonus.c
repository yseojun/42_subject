/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_sprites_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:23:11 by rolee             #+#    #+#             */
/*   Updated: 2023/07/13 12:42:39 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_bonus.h"

static t_sprite		*sprites_realloc(t_info *info, int y, int x);
static void			set_sprite_frames(t_info *info, t_sprite *sprite, \
	char type);
static const char	*chk_sprite_type(t_sprite *sprite, char type);

void	set_sprites(t_info *info)
{
	int	i;
	int	j;

	info->sprite_cnt = 0;
	info->sprites = NULL;
	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (is_sprite(info->map[i][j]))
				info->sprites = sprites_realloc(info, i, j);
			j++;
		}
		i++;
	}
}

static t_sprite	*sprites_realloc(t_info *info, int y, int x)
{
	t_sprite	*new_sprites;
	t_sprite	new_sprite;
	int			idx;

	new_sprite.pos[X] = x + 0.5;
	new_sprite.pos[Y] = y + 0.5;
	new_sprite.idx = 0;
	set_sprite_frames(info, &new_sprite, info->map[y][x]);
	new_sprites = (t_sprite *)malloc(sizeof(t_sprite) * (info->sprite_cnt + 1));
	if (!new_sprites)
		exit(occur_error(MALLOC_FAILED));
	new_sprites[info->sprite_cnt] = new_sprite;
	idx = info->sprite_cnt - 1;
	while (idx >= 0)
	{
		new_sprites[idx] = info->sprites[idx];
		idx--;
	}
	if (info->sprites)
		free(info->sprites);
	info->sprite_cnt++;
	return (new_sprites);
}

static	void	set_sprite_frames(t_info *info, t_sprite *sprite, char type)
{
	int			idx;
	const char	*file_type;
	char		*file_name;
	char		*total_name;
	char		*frame_num;

	file_type = chk_sprite_type(sprite, type);
	sprite->frame = (t_img *)malloc(sizeof(t_img) * sprite->frame_cnt);
	if (!sprite->frame)
		exit(occur_error(MALLOC_FAILED));
	idx = 0;
	while (idx < sprite->frame_cnt)
	{
		frame_num = ft_itoa(idx);
		file_name = ft_strjoin(file_type, frame_num);
		total_name = ft_strjoin(file_name, ".xpm");
		sprite->frame[idx] = load_to_image(info, total_name);
		free(frame_num);
		free(file_name);
		free(total_name);
		idx++;
	}
}

static const char	*chk_sprite_type(t_sprite *sprite, char type)
{
	if (type == '3')
	{
		sprite->frame_cnt = 10;
		sprite->u_div = 1.5;
		sprite->v_div = 1.5;
		sprite->v_move = 500;
		return ("./textures/mew_idle/mew_idle00");
	}
	else if (type == '4')
	{
		sprite->frame_cnt = 13;
		sprite->u_div = 1.5;
		sprite->v_div = 1.5;
		sprite->v_move = 500;
		return ("./textures/cat_stretching/cat_stretching_00");
	}
	else
	{
		sprite->frame_cnt = 19;
		sprite->u_div = 1.5;
		sprite->v_div = 1.5;
		sprite->v_move = 500;
		return ("./textures/cat_lying/cat_lying_00");
	}
}
