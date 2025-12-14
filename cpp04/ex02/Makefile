CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -Wshadow -std=c++98
NAME 		= ex02

BUILD_PATH  = .build
SRC_PATH    = src
INC_PATH    = inc
INCLUDES    = -I$(INC_PATH)

SRCS 		=	main.cpp Animal.cpp Dog.cpp Cat.cpp \
		WrongCat.cpp WrongAnimal.cpp Brain.cpp

OBJS        = $(SRCS:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

RM          = rm -fr
MKDIR       = mkdir -p

V_ARGS      = --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re