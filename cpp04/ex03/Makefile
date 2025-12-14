CXX         = c++
# CXXFLAGS    = -std=c++98 
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 
NAME        = ex03


BUILD_PATH  = .build
SRC_PATH    = src
INC_PATH    = inc
INCLUDES    = -I$(INC_PATH)

SRCS        = $(addprefix $(SRC_PATH)/, main.cpp \
										AMateria.cpp \
										Character.cpp \
										Cure.cpp \
										Ice.cpp \
										MateriaSource.cpp \
				)
OBJS        = $(SRCS:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

RM          = rm -fr
MKDIR       = mkdir -p

V_ARGS      = --leak-check=full --show-leak-kinds=all --track-origins=yes


all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking ..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "Build complete!"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	@$(MKDIR) $(BUILD_PATH)
	@echo "Compiling ..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@


val: $(NAME)
	@echo "Running valgrind on $(NAME)..."
	@valgrind $(V_ARGS) ./$(NAME)


clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS) $(BUILD_PATH)

fclean: clean
	@echo "Removing executable and build directory..."
	@$(RM) $(NAME)

re: fclean all
	@echo "Rebuilding $(NAME)..."
.PHONY: all clean fclean re val