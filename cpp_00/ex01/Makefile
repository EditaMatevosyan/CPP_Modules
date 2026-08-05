NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS = \
	main.cpp \
	PhoneBook.cpp \
	Contact.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = \
	PhoneBook.hpp \
	Contact.hpp

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

.PHONY: all clean fclean re