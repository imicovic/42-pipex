CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
TARGET	= libft.a
YELLOW	= \033[0;33m
GREEN	= \033[0;32m
NC		= \033[0m

all: message $(TARGET)
	@echo "$(GREEN)$(TARGET): SUCCESS$(NC)"
	@sleep 0.3

$(TARGET): $(OBJS)
	@ar rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

message:
	@echo "$(YELLOW)------------------Compiling libft.a...------------------$(NC)"

clean:
	@rm -f $(OBJS) $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
