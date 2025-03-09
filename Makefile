CC		= clang
CFLAGS	= -Wall -Wextra -Werror
NAME	= pipex
LIB		= lib/libft.a
SRC		= src/pipex.c\
		  src/utils.c
OBJ		= $(SRC:.c=.o)
BOBJ	= $(BSRC:.c=.o)
BSRC	= src_bonus/pipex_bonus.c\
		  src_bonus/utils_bonus.c
YELLOW	= \033[0;33m
GREEN	= \033[0;32m
RED		= \033[0;31m
NC		= \033[0m

all: $(NAME)
	@echo "$(GREEN)pipex:   SUCCESS$(NC)"
	@echo
	@echo "$(GREEN)./pipex infile \"cmd1\" \"cmd2\" outfile$(NC)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

bonus: $(BOBJ)
	@echo "$(GREEN)pipex:   SUCCESS$(NC)"
	@echo
	@echo "$(GREEN)./pipex infile \"cmd1\" \"cmd2\" \"cmd3\"... \"cmdn\" outfile$(NC)"
	@$(CC) $(CFLAGS) $(BOBJ) $(LIB) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): $(LIB)

$(BOBJ): $(LIB)

$(LIB):
	@make -C lib
	@echo "$(YELLOW)-------------------Compiling pipex...-------------------$(NC)"
	@sleep 0.3

re: fclean all

clean:
	@echo "$(YELLOW)Removing all object and library files...$(NC)"
	@sleep 0.3
	@make clean -C lib
	@rm -f $(OBJ) $(BOBJ) $(LIB)

fclean: clean
	@echo "$(YELLOW)Removing an executable...$(NC)"
	@sleep 0.5
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus
