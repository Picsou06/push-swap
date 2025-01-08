NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -I include

SRC =\
		./src/parsing/ft_parse.c \
		main.c \
		./src/debug/show.c \

OBJ = $(SRC:.c=.o)

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

all : parsing sorting stack_utils $(NAME)

$(NAME) : $(OBJ)
			@echo "$(YELLOW)Compiling my beautiful libft...$(RESET)"
			@make -s -C libft
			@clang -o $(NAME) $(OBJ) $(CFLAGS) -I libft libft/libft.a
			@echo "$(GREEN)Compilation finished.$(RESET)"

# Custom rules to compile folders
parsing: $(filter ./src/parsing/%.o, $(OBJ))
			@echo "$(YELLOW)Compiling parsing...$(RESET)"
			@echo "$(GREEN)parsing compiled successfully.$(RESET)"

sorting: $(filter ./src/sorting/%.o, $(OBJ))
			@echo "$(YELLOW)Compiling sorting...$(RESET)"
			@echo "$(GREEN)sorting compiled successfully.$(RESET)"

stack_utils: $(filter ./src/stack_utils/%.o, $(OBJ))
			@echo "$(YELLOW)Compiling stack_utils...$(RESET)"
			@echo "$(GREEN)stack_utils compiled successfully.$(RESET)"

# Per-file compilation rules
./src/stack_utils/%.o: ./src/stack_utils/%.c
			@clang $(CFLAGS) -c $< -o $@

./src/parsing/%.o: ./src/parsing/%.c
			@clang $(CFLAGS) -c $< -o $@

./src/sorting/%.o: ./src/sorting/%.c
			@clang $(CFLAGS) -c $< -o $@

%.o: %.c
			@clang $(CFLAGS) -c $< -o $@

clean :
			@echo "$(YELLOW)Cleaning object files...$(RESET)"
			@rm -rf $(OBJ)
			@echo "$(GREEN)Cleaning complete.$(RESET)"
			@make -s clean -C libft

fclean : clean
			@echo "$(YELLOW)Cleaning executable...$(RESET)"
			@rm -rf $(NAME)
			@echo "$(GREEN)Full cleaning complete.$(RESET)"
			@make -s fclean -C libft

re : fclean all

.PHONY : all clean fclean re parsing sorting stack_utils
