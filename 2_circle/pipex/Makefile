NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory.c \
info.c \
check.c
SRCS_BONUS = bonus.c \
check_bonus.c \
info_bonus.c \
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
	rm -f $(OBJS_BONUS)

bonus : $(OBJS_BONUS)
	make all -C $(LBFT)
	$(CC) $(CFLAGS) -o $(NAME) $^ -L$(LBFT) -lft
	rm -f $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LBFT)

re :
	make fclean
	make all

.PHONY: clean fclean re