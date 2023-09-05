/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:19 by rolee             #+#    #+#             */
/*   Updated: 2023/07/13 16:21:51 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 2)
		return (occur_error(INVALID_ARGU));
	info = set_info(argv[1]);
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "cub3d");
	display_world(&info);
	manage_event(&info);
	mlx_loop(info.mlx);
	return (0);
}
