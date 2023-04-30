/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:07:09 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/09 15:23:15 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "util.h"
#include "draw.h"

void	check_av(char **av);
int		key_hook(int keycode, t_map *map);
int		exit_cross(void);

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (0);
	check_av(av);
	init_map(&map);
	parse_map(&map, av[1]);
	init_value(&map);
	map.draw = init_draw(&map);
	parse_value(&map, av[1]);
	map.mlx.mlx = mlx_init();
	map.mlx.win = mlx_new_window(map.mlx.mlx, 2500, 1200, "fdf");
	map.img.img = mlx_new_image(map.mlx.mlx, 2500, 1200);
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_per_pixel, \
									&map.img.line_length, &map.img.endian);
	cal_draw(&map, map.draw);
	draw_all(&map, map.draw);
	mlx_put_image_to_window(map.mlx.mlx, map.mlx.win, map.img.img, 0, 0);
	mlx_hook(map.mlx.win, 2, 0, key_hook, &map);
	mlx_hook(map.mlx.win, 17, 0, exit_cross, 0);
	mlx_loop(map.mlx.mlx);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		exit(0);
	}
	return (0);
}

void	check_av(char **av)
{
	char	**name;
	int		fd;
	int		idx;

	idx = 0;
	fd = open(av[1], O_RDONLY);
	name = ft_split(av[1], '.');
	while (name[idx])
		idx++;
	if (fd < 0 || ft_strncmp(name[idx - 1], "fdf", 4) != 0)
	{
		ft_putendl_fd("Wrong file", 2);
		exit(1);
	}
	free_arr((void *)name);
}

int	exit_cross(void)
{
	exit(0);
	return (0);
}

void	wrong_exit(char *msg)
{
	ft_putstr_fd("Wrong ", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(1);
}
