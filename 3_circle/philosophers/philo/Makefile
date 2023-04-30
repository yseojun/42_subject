NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory.c \
action.c \
servant_life.c \
init_info.c \
init_philo.c \
philo_life.c \
time.c \
util.c
OBJS = $(addprefix srcs/, $(SRCS:.c=.o))

all : $(NAME)

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