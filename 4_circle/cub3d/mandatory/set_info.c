/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:41:36 by seojyang          #+#    #+#             */
/*   Updated: 2023/07/24 11:28:59 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

static void	check_file_extension(char *path);
static void	init_ev(t_info *info);
static void	set_imgs(t_info *info);

t_info	set_info(char *path)
{
	t_info	info;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(occur_error(INVALID_FILE));
	check_file_extension(path);
	info.mlx = mlx_init();
	if (!info.mlx)
		exit(occur_error(MLX_INIT_FAILED));
	init_ev(&info);
	set_graphic_info(&info, fd);
	set_map_info(&info, fd);
	check_valid_map(info);
	set_player_info(&info);
	set_imgs(&info);
	return (info);
}

static void	check_file_extension(char *path)
{
	char	*name;
	int		start;

	name = ft_strrchr(path, '/');
	if (!name)
		name = path;
	else
		name += 1;
	start = ft_strlen(name) - 4;
	if (!start || ft_strncmp(name + start, ".cub", 4))
		exit(occur_error(INVALID_FILE_EXTENSION));
}

static void	init_ev(t_info *info)
{
	info->ev.push_a = FALSE;
	info->ev.push_d = FALSE;
	info->ev.push_s = FALSE;
	info->ev.push_w = FALSE;
	info->ev.push_left = FALSE;
	info->ev.push_right = FALSE;
}

static void	set_imgs(t_info *info)
{
	info->frame.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->frame.addr = mlx_get_data_addr(info->frame.img, &info->frame.bits, \
		&info->frame.line_length, &info->frame.endian);
}
