NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_hex.c ft_mem.c ft_itoa.c ft_put.c \
	ft_string.c ft_string2.c ft_uitoa.c \
	ft_printf.c \
	p_info.c \
	p_before_after.c \
	p_make.c 
SRCS_BONUS = test.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^
	touch all
	rm -f bonus

bonus : $(OBJS_BONUS)
	ar rcs $(NAME) $^
	touch bonus
	rm -f all

%.o: %.c
	$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

clean:
	rm -f $(OBJS_BONUS) $(OBJS)

fclean: clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: clean fclean re