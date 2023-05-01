NAME =

CC =
CFLAGS = -Wall -Wextra -Werror

SRCS =
OBJS = $(SRCS:.cpp=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re