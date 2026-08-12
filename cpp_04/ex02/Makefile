NAME = abstract

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   Animal.cpp \
	   Cat.cpp \
	   Dog.cpp \
	   WrongAnimal.cpp \
	   WrongCat.cpp \
	   Brain.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Animal.hpp \
		  Cat.hpp \
		  Dog.hpp \
		  WrongAnimal.hpp \
		  WrongCat.hpp \
		  Brain.hpp

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re abstract