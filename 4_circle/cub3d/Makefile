NAME = cub3D

SRCS = main.c \
utils.c \
set_info.c \
set_info_graphic.c \
set_info_map.c \
set_info_check_map.c \
set_info_player.c \
display_world.c \
display_set_ray.c \
display_get_line_height.c \
display_set_frame.c \
manage_event.c \
event_move_to.c \
event_move_rotate.c

BONUS_SRCS = main_bonus.c \
utils_bonus.c \
utils_graphic_bonus.c \
set_info_bonus.c \
set_info_graphic_bonus.c \
set_info_map_bonus.c \
set_info_map_check_bonus.c \
set_info_sprites_bonus.c \
set_info_player_bonus.c \
display_world_bonus.c \
display_set_ray_bonus.c \
display_get_line_height_bonus.c \
display_set_frame_bonus.c \
display_minimap_bonus.c \
display_sprites_bonus.c \
display_each_sprite_bonus.c \
manage_event_bonus.c \
event_move_to_bonus.c \
event_move_rotate_bonus.c \
manage_door_bonus.c

OBJS = $(addprefix mandatory/, $(SRCS:.c=.o))\
	$(GNL:.c=.o)
BONUS_OBJS = $(addprefix bonus/, $(BONUS_SRCS:.c=.o))\
	$(GNL:.c=.o)

GNL = gnl/get_next_line_bonus.c \
gnl/get_next_line_utils_bonus.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g

ifdef BONUS
	OBJ = $(BONUS_OBJS)
else
	OBJ = $(OBJS)
endif

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft all -j6
	make -C mlx all -j6
	$(CC) $(FLAGS) $^ libft/libft.a -Lmlx -lmlx -framework OpenGL -framework Appkit -o $@

bonus :
	make BONUS=1 all

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	make -C libft clean
	make -C mlx clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus