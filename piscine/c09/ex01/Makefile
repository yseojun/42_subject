NAME = libft.a
GCC = gcc -Wall -Werror -Wextra
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INC = includes/ft.h

all : $(NAME)

$(OBJS) : $(SRCS)
	$(GCC) -c -o $@ -I $(INC) $<

$(NAME) : $(OBJS)
	ar -rcs $@ $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean clean
