##
## Loris
##

CXX		= g++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++11 -I ./includes

RM		= rm -f

NAME		= indie_studio

SRCS		= srcs/main.cpp \
		  srcs/indie.cpp

OBJS		= $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	 @$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
