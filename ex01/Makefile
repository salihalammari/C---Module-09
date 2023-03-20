NAME = RPN
CXX = c++
RM = rm -rf

HEADERS = RPN.hpp

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =	main.cpp RPN.cpp

OBJT = $(SRCS:.cpp=.o)
all : $(NAME)

$(NAME): $(OBJT)
	$(CXX) $(CXXFLAGS) $(OBJT) -o $(NAME)

%.o: %.cpp  $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJT)
fclean:
	$(RM) $(OBJT) $(NAME)
re:	fclean all

.PHONY: all fclean clean re