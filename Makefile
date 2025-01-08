NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -I include

SRC =\
		./src/parsing/ft_parse.c \
		./src/main.c \
		./src/debug/show.c \

OBJ = $(SRC:.c=.o)

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

all : compiling $(NAME)

$(NAME) : $(OBJ)
			@echo "$(YELLOW)Compiling my beautiful libft...$(RESET)"
			@make -s -C libft
			@clang -o $(NAME) $(OBJ) $(CFLAGS) -I libft libft/libft.a
			@echo "$(GREEN)Compilation finished.$(RESET)"

compiling: $(filter ./src/%.o, $(OBJ))
			@echo "$(YELLOW)Compiling...$(RESET)"
			@echo "$(GREEN)Compiling ended successfully.$(RESET)"

./src/%.o: ./src/%.c
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
