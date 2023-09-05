/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:34:03 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/13 16:47:38 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static char		**read_map(int fd, char *temp);
static char		**map_realloc(char **map, char *map_str);
static int		get_map_width(char **map);
static void		set_rectangle_map(t_info *info, char **tmp_map);

void	set_map_info(t_info *info, int fd)
{
	char	*temp;
	char	**tmp_map;

	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			exit(occur_error(INVALID_MAP));
		if (ft_strncmp(temp, "\n", 2))
			break ;
		free(temp);
	}
	tmp_map = read_map(fd, temp);
	info->map_size[HEI] = str_arr_len(tmp_map);
	info->map_size[WID] = get_map_width(tmp_map);
	set_rectangle_map(info, tmp_map);
	free_str_arr(tmp_map);
}

static char	**read_map(int fd, char *temp)
{
	char	*map_str;
	char	**map;

	map = NULL;
	while (1)
	{
		map_str = ft_strtrim(temp, "\n");
		free(temp);
		map = map_realloc(map, map_str);
		free(map_str);
		temp = get_next_line(fd);
		if (!temp)
			break ;
		if (ft_strncmp(temp, "\n", 2) == 0)
			exit(occur_error(INVALID_MAP));
	}
	return (map);
}

static char	**map_realloc(char **map, char *map_str)
{
	int		height;
	char	**new;

	height = 0;
	if (map)
	{
		while (map[height])
			height++;
	}
	new = (char **)malloc(sizeof(char *) * (height + 2));
	if (!new)
		exit(occur_error(MALLOC_FAILED));
	new[height + 1] = NULL;
	new[height] = ft_strdup(map_str);
	while (height > 0)
	{
		new[height - 1] = ft_strdup(map[height - 1]);
		height--;
	}
	free_str_arr(map);
	return (new);
}

static int	get_map_width(char **map)
{
	int	max_width;
	int	idx;

	max_width = 0;
	idx = 0;
	while (map[idx])
	{
		if (max_width < (int)ft_strlen(map[idx]))
			max_width = ft_strlen(map[idx]);
		idx++;
	}
	return (max_width);
}

static void	set_rectangle_map(t_info *info, char **tmp_map)
{
	int		i;
	int		j;

	info->map = (char **)malloc(sizeof(char *) * (info->map_size[HEI] + 1));
	if (!info->map)
		exit(occur_error(MALLOC_FAILED));
	i = 0;
	info->map[info->map_size[HEI]] = NULL;
	while (tmp_map[i])
	{
		info->map[i] = (char *)malloc(info->map_size[WID] + 1);
		if (!info->map[i])
			exit(occur_error(MALLOC_FAILED));
		j = 0;
		while (j < info->map_size[WID])
		{
			info->map[i][j] = ' ';
			if (j < (int)ft_strlen(tmp_map[i]))
				info->map[i][j] = tmp_map[i][j];
			j++;
		}
		info->map[i][j] = '\0';
		i++;
	}
}
