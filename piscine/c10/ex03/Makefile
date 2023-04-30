NAME = ft_hexdump
GCC = gcc -Wall -Werror -Wextra
SRCS = srcs/main.c srcs/print.c srcs/string.c srcs/util.c
INC = includes/

all : $(NAME)

$(NAME) : $(SRCS)
	$(GCC) -o $@ $^ -I $(INC)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean clean re
