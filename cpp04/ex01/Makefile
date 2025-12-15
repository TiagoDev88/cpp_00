CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -Wshadow -std=c++98
NAME 		= ex01

BUILD_PATH  = .build
SRC_PATH    = src
INC_PATH    = inc
INCLUDES    = -I$(INC_PATH)

SRCS 		= $(addprefix $(SRC_PATH)/, main.cpp \
                                        Animal.cpp \
                                        Dog.cpp \
                                        Cat.cpp \
                                        WrongCat.cpp \
                                        WrongAnimal.cpp \
                                        Brain.cpp)

OBJS        = $(SRCS:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

RM          = rm -fr
MKDIR       = mkdir -p

V_ARGS      = --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

$(BUILD_PATH):
	@$(MKDIR) $(BUILD_PATH)

$(NAME): $(BUILD_PATH) $(OBJS)
	@echo "Linking ..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "Build complete!"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp | $(BUILD_PATH)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

val: $(NAME)
	@echo "Running valgrind on $(NAME)..."
	@valgrind $(V_ARGS) ./$(NAME)

clean:
	@echo "Cleaning object files..."
	@$(RM) $(BUILD_PATH)

fclean: clean
	@echo "Removing executable..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re val