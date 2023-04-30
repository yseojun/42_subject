NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory.c \
check.c \
operater_main.c \
operater_push_swap.c \
operater_rotate.c \
stack.c \
struct.c \
sort_util_for_34.c \
sort_util_for_45.c \
sort_under_5.c \
sort_main.c \
triangle.c
SRCS_BONUS = main_bonus.c \
operater_main_bonus.c \
operater_push_swap_bonus.c \
operater_rotate_bonus.c \
stack_bonus.c \
check_bonus.c \
get_next_line_bonus.c \
get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(addprefix bonus/, $(SRCS_BONUS:.c=.o))
LBFT = libft
LBFTAR = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LBFT) -lft

bonus : $(OBJS_BONUS)
	make all -C $(LBFT)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) -L$(LBFT) -lft

%.o: %.c
	$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LBFT)

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C $(LBFT)

re :
	make fclean
	make all

.PHONY: clean fclean re