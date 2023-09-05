/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:52:25 by rolee             #+#    #+#             */
/*   Updated: 2023/07/20 18:38:29 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "../gnl/get_next_line_bonus.h"
# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1
# define SUCCESS 0
# define FAILURE -1

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_SPACE 49
# define KEY_ESC 53
# define CLOSE_BUTTON 17
# define KEY_PRESS 2
# define KEY_RELEASE 3

# define WIDTH 2000
# define HEIGHT 1000

# define WID 0
# define HEI 1
# define MINIMAP_ROOM 18
# define MINIMAP_DIVIER	2

# define X 0
# define Y 1
# define POV 1
# define SPEED 0.1
# define ANGLE 0.1

# define N 0
# define W 1
# define S 2
# define E 3

# define INVALID_ARGU "invalid Argument."
# define INVALID_FILE "invalid file path."
# define INVALID_FILE_EXTENSION "invalid file extension."
# define MLX_INIT_FAILED "mlx_init() failed."
# define MALLOC_FAILED "malloc failed."
# define INVALID_FORMAT "file content format is incorrect."
# define INVALID_RGB "rgb value out of range."
# define INVALID_TEXTURE "invalid texture file"
# define INVALID_WALL "map is not surrounded by walls."
# define INVALID_MAP "invalid map."
# define INVALID_PLAYER "map must contain one player."
# define INVALID_MAP_CAHR "map must only contain numbers [0-1], \
[N,S,W,E] and space."

typedef struct s_player
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
}	t_player;

typedef struct s_draw
{
	int	from_x;
	int	from_y;
	int	to_x;
	int	to_y;
	int	dx;
	int	dy;
	int	f;
	int	df_1;
	int	df_2;
}	t_draw;

typedef struct s_ray
{
	double	ray_dir[2];
	int		hit[2];
	int		step[2];
	double	delta_dist[2];
	double	side_dist[2];
	int		side;
	double	perp_wall_dist;
	int		dir;
	int		start;
	int		end;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		endian;
	int		bits;
	int		line_length;
	int		height;
	int		width;
}	t_img;

typedef struct s_tex_info
{
	int		*texture_int;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_tex_info;

typedef struct s_event
{
	int	push_w;
	int	push_a;
	int	push_s;
	int	push_d;
	int	push_left;
	int	push_right;
}	t_event;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	char			**map;
	int				map_size[2];
	struct s_img	frame;
	struct s_img	texture[4];
	int				f_color[3];
	int				c_color[3];
	t_player		player;
	t_event			ev;
}	t_info;

t_info	set_info(char *path);
void	set_graphic_info(t_info *info, int fd);
void	set_map_info(t_info *info, int fd);
void	check_valid_map(t_info info);
void	set_player_info(t_info *info);

void	free_str_arr(char **str_arr);
int		str_arr_len(char **str_arr);
int		encode_rgb(int color[3]);
int		finish_game(t_info *info);
int		occur_error(char *message);

void	display_world(t_info *info);
t_ray	set_ray(t_info *info, int x);
int		get_line_height(t_info *info, t_ray *ray);
void	set_frame(t_info *info, t_ray *ray, int x, int line_height);

void	manage_event(t_info *info);

void	move(t_info *info, double val);
void	move_up(t_info *info, double val);
void	move_down(t_info *info, double val);
void	move_left(t_info *info, double val);
void	move_right(t_info *info, double val);
void	rotate(t_info *info, int sign, double angle);

t_draw	make_dr_info(int from_x, int fromY, int to_x, int to_y);

#endif