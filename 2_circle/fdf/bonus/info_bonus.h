/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:52:37 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/09 14:21:03 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_BONUS_H
# define INFO_BONUS_H

# include "../libft/libft.h"
# include "../gnl/get_next_line_bonus.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_draw
{
	double	y;
	double	x;
	int		color;
}	t_draw;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_map
{
	int				width;
	int				height;
	int				**value;
	int				**color;
	int				is_color;
	double			magnitude;
	double			degree;
	int				max;
	int				min;
	int				x_min;
	int				x_max;
	int				y_min;
	int				y_max;
	double			x_degree;
	double			y_degree;
	double			z_degree;
	int				x_move;
	int				y_move;
	struct s_img	img;
	struct s_point	**point;
	struct s_draw	**draw;
	struct s_mlx	mlx;
}	t_map;

void	init_map(t_map *map);
void	init_value(t_map *map);
t_draw	**init_draw(t_map *map);
void	init_color(t_map *map);
t_point	**init_point(t_map *map);
void	reset_min_max(t_map *map, t_draw **draw);

void	cal_draw(t_map *map, t_draw **draw);
void	revise_draw(t_map *map, t_draw **draw);
int		set_magnitude(t_map *map);
void	update_size(t_map *map, double y, double x);
int		value_to_color(t_map *map, int height, int width);

void	parse_map(t_map *map, char *infile);
void	parse_value(t_map *map, char *infile);
void	parse_value_one_line(t_map *map, char **line_spl, int height);
void	map_min_max_update(t_map *map, int height, int width, int value);
void	get_width(t_map *map, char **line_spl);

void	wrong_exit(char *msg);

#endif
