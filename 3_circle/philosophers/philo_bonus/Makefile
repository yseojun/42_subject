NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = bonus.c \
action_bonus.c \
servant_life_bonus.c \
init_info_bonus.c \
philo_life_bonus.c \
time_bonus.c \
util_bonus.c \
util2_bonus.c
OBJS = $(addprefix srcs/, $(SRCS:.c=.o))

all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re