/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:33 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/13 16:48:43 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static t_player	make_player(int x, int y, char dir);

void	set_player_info(t_info *info)
{
	int	i;
	int	j;
	int	player_cnt;

	player_cnt = 0;
	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'W' || info->map[i][j] == 'E')
			{
				info->player = make_player(j, i, info->map[i][j]);
				info->map[i][j] = '0';
				player_cnt++;
			}
			j++;
		}
		i++;
	}
	if (player_cnt != 1)
		exit(occur_error(INVALID_PLAYER));
}

static t_player	make_player(int x, int y, char dir)
{
	t_player	player;
	const int	dxy[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
	const char	dd[4] = {'N', 'S', 'W', 'E'};
	int			i;

	player.pos[X] = x + 0.5;
	player.pos[Y] = y + 0.5;
	i = 0;
	while (i < 4)
	{
		if (dir == dd[i])
		{
			player.dir[X] = dxy[X][i];
			player.dir[Y] = dxy[Y][i];
			player.plane[X] = -dxy[Y][i] * POV;
			player.plane[Y] = dxy[X][i] * POV;
			break ;
		}
		i++;
	}
	return (player);
}
