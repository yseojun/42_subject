NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory.c \
parse.c \
util.c \
init.c \
cal.c \
draw.c \
draw_util.c
SRCS_BONUS = bonus.c \
parse_bonus.c \
util_bonus.c \
init_bonus.c \
cal_bonus.c \
draw_bonus.c \
draw_util_bonus.c \
hook_bonus.c \
hook_rotate_bonus.c
OBJS = $(addprefix srcs/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix bonus/, $(SRCS_BONUS:.c=.o))
CLIB = -L minilibx_macos -l mlx -framework OpenGL -framework Appkit -I minilibx_macos
LBFT = libft
LBFTAR = libft/libft.a
GNL = gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LBFT)
	$(CC) $(CFLAGS) -o $@ $(CLIB) $^ $(GNL) -L$(LBFT) -lft
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	rm -f $(OBJS_BONUS)

bonus : $(OBJS_BONUS)
	make all -C $(LBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(CLIB) $^ $(GNL) -L$(LBFT) -lft
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	rm -f $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

clean:
	make clean -C $(LBFT)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LBFT)
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: clean fclean re