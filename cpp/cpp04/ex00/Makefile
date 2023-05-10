NAME = ex00

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	Animal.cpp \
	Dog.cpp \
	Cat.cpp
SRCS_WRONG = main_wrong.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)
OBJS_WRONG = $(SRCS_WRONG:.cpp=.o)

%.o : %.c
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

wrong : $(OBJS_WRONG)
	$(CC) $(CXXFLAGS) -o $(NAME) $(SRCS_WRONG)

clean :
	rm -f $(OBJS) $(OBJS_WRONG)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re