/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:36:21 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/09 15:17:16 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"
#include "info_bonus.h"

void	parse_map(t_map *map, char *infile)
{
	int		fd;
	char	*line;
	char	*for_free;
	char	**line_spl;

	fd = open(infile, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		for_free = line;
		if (!line)
			break ;
		line = ft_strtrim(line, "\n");
		free(for_free);
		line_spl = ft_split(line, ' ');
		get_width(map, line_spl);
		map->height++;
		free_arr((void *)line_spl);
		free(line);
	}
	close(fd);
}

void	get_width(t_map *map, char **line_spl)
{
	int		check;
	char	**val_clr;

	check = 0;
	while (line_spl[check])
	{
		if (!is_digit(line_spl[check]))
		{
			val_clr = ft_split(line_spl[check], ',');
			if (!is_digit(val_clr[0]))
				wrong_exit("value");
			if (!is_color(val_clr[1]))
				wrong_exit("color");
			free_arr((void *)val_clr);
		}
		check++;
	}
	if (map->width == 0)
		map->width = check;
	else if (check != map->width)
		wrong_exit("map size");
}

void	parse_value(t_map *map, char *infile)
{
	int		fd;
	char	*line;
	char	**line_spl;
	int		height;

	fd = open(infile, O_RDONLY);
	height = 0;
	while (height < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_spl = ft_split(line, ' ');
		parse_value_one_line(map, line_spl, height);
		free_arr((void *)line_spl);
		free(line);
		height++;
	}
	close(fd);
}

void	parse_value_one_line(t_map *map, char **line_spl, int height)
{
	int		width;
	int		value;
	char	**val_clr;

	width = 0;
	while (width < map->width)
	{
		val_clr = ft_split(line_spl[width], ',');
		value = ft_atoi(val_clr[0]);
		if (!val_clr[1] && map->is_color == 1)
			map->draw[height][width].color = 0xffffff;
		if (val_clr[1])
		{
			map->draw[height][width].color = atohex(val_clr[1]);
			map->is_color = 1;
		}
		map_min_max_update(map, height, width, value);
		map->value[height][width++] = value;
		free_arr((void *)val_clr);
	}
}

void	map_min_max_update(t_map *map, int height, int width, int value)
{
	if (height == 0 && width == 0)
	{
		map->max = value;
		map->min = value;
	}
	if (value > map->max)
		map->max = value;
	if (value < map->min)
		map->min = value;
}
