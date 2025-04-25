NAME			=	philo
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3

SRC_DIR			=	./
OBJ_DIR			=	objs/

SRC_FILES		=	main.c atol.c action.c \
					init.c philo.c utils.c getter.c setter.c destroy.c

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)%.o: %.c philo.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS) Makefile philo.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
