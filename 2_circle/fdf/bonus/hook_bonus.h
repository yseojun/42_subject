/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:54:54 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/07 17:16:08 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_BONUS_H
# define HOOK_BONUS_H

# include "info_bonus.h"

void	_move(t_map *map, t_draw **draw, int keycode);
void	_zoom(t_map *map, t_draw **draw, int keycode);
void	_refresh(t_map *map, t_draw **draw);
void	reset_min_max(t_map *map, t_draw **draw);
void	_rotate(t_map *map, t_draw **draw, t_point **point);
void	revise_draw_rotate(t_map *map, t_draw **draw);

void	rotate_xyz(t_map *map, t_point *point);
void	change_degree(t_map *map, int keycode);
void	set_point(t_map *map, t_point *point, int height, int width);
void	conic_projection(t_map *map, t_draw **draw);

#endif