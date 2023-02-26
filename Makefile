NAME		= rush-02
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 -I includes/
RM			= rm -rf

MAIN		= dict main
UTILS		= compare free gnl join split

SRCS		= $(addsuffix .c, $(addprefix srcs/main/, $(MAIN))) \
				$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS))) \

OBJ			= $(SRCS:%.c=%.o)

all : $(NAME)

%.o : %.c
	@echo "\033[0;33mCompiling $<\033[0m"
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@echo "\033[0;32mRush02\033[0m"
	@$(CC) $(FLAGS) $^ -o $@

clean:
	@echo "\033[0;31mRemoving objects...\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@echo "\033[0;31mDeleting Rush02...\033[0m"
	@$(RM) $(NAME)

re : fclean all