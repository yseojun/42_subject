/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:27:49 by rolee             #+#    #+#             */
/*   Updated: 2023/07/13 16:48:31 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static void	check_edge(t_info info, int y);
static void	check_map_char(char c);
static void	check_around(char **map, int y, int x);

void	check_valid_map(t_info info)
{
	int	y;
	int	x;

	y = 0;
	while (info.map[y])
	{
		check_edge(info, y);
		x = 0;
		while (info.map[y][x])
		{
			check_map_char(info.map[y][x]);
			if (info.map[y][x] != '1' && info.map[y][x] != ' ')
				check_around(info.map, y, x);
			x++;
		}
		y++;
	}
}

static void	check_edge(t_info info, int y)
{
	int	idx;

	if (y == 0 || y == info.map_size[HEI] - 1)
	{
		idx = 0;
		while (info.map[y][idx])
		{
			if (info.map[y][idx] != '1' && info.map[y][idx] != ' ')
				exit(occur_error(INVALID_WALL));
			idx++;
		}
	}
	if (info.map[y][0] != '1' && info.map[y][0] != ' ')
		exit(occur_error(INVALID_WALL));
	if (info.map[y][info.map_size[WID] - 1] != '1'
		&& info.map[y][info.map_size[WID] - 1] != ' ')
		exit(occur_error(INVALID_WALL));
}

static void	check_map_char(char c)
{
	if (c != ' ' && c != '0' && c != '1' && \
		c != 'N' && c != 'S' && c != 'W' && c != 'E')
		exit(occur_error(INVALID_MAP_CAHR));
}

static void	check_around(char **map, int y, int x)
{
	if (map[y][x + 1] == ' ' || map[y][x + 1] == '\0')
		exit(occur_error(INVALID_WALL));
	if (map[y][x - 1] == ' ' || map[y][x - 1] == '\0')
		exit(occur_error(INVALID_WALL));
	if (map[y + 1][x] == ' ' || map[y + 1][x] == '\0')
		exit(occur_error(INVALID_WALL));
	if (map[y - 1][x] == ' ' || map[y - 1][x] == '\0')
		exit(occur_error(INVALID_WALL));
}
