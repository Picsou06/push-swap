NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -I include

SRC =\
		./src/parsing/ft_parse.c \
		./src/sorting/sort_big.c \
		./src/sorting/sort_small.c \
		./src/sorting/sort_three.c \
		./src/sorting/sort_four.c \
		./src/sorting/sort_five.c \
		./src/sorting/sorting.c \
		./src/utils/initialisation.c \
		./src/utils/operations.c \
		./src/utils/operations2.c \
		./src/utils/operations3.c \
		./src/utils/utils.c \
		./src/utils/utils2.c \
		./src/main.c \

OBJ = $(SRC:.c=.o)

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

all : $(NAME)

$(NAME) : $(OBJ)
			@echo "$(YELLOW)Compiling my libft...$(RESET)"
			@make -s -C libft
			@echo "$(YELLOW)Linking...$(RESET)"
			@clang -o $(NAME) $(OBJ) $(CFLAGS) -I libft libft/libft.a
			@echo "$(GREEN)Compilation finished.$(RESET)"

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