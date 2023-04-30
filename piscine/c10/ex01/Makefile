NAME = ft_cat
GCC = gcc -Wall -Werror -Wextra
SRCS = srcs/main.c srcs/util.c

all : $(NAME)

$(NAME) : $(SRCS)
	$(GCC) -o $@ $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean clean re
