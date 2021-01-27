CC = gcc
FLAGS = -Wextra -Werror -Wall 
NAME = miniRT

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC =	\
		math/vec_op.c


SRCS = $(addprefix $(SRC))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -I $(DIR_H) -c $< -o $@

all: $(NAME)


