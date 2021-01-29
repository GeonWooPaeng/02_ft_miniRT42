CC = gcc
FLAGS = -Wextra -Werror -Wall 
NAME = miniRT

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC =	\
		vec_op.c \
		main.c


SRCS = $(addprefix $(DIR_S),$(SRC))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx-linux
	gcc -o $(NAME) $(OBJS) $(CFLAGS) -lmlx -L./minilibx-linux -lm

clean:
	rm -rf $(OBJS)

fclean:
	clean
	rm -rf $(NAME)

re:
	fclean all

.PHONY: clean fclaen all re 

