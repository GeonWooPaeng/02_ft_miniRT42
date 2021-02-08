CC = gcc
FLAGS = -Wextra -Werror -Wall 
NAME = miniRT

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC =	\
		vec_op.c			\
		ray.c				\
		ft_camera.c			\
		hittable_list.c		\
		hittable.c			\
		sphere.c			\
		utils.c				\
		utils2.c			\
		utils3.c			\
		ft_random.c			\
		get_next_line.c		\
		main.c


SRCS = $(addprefix $(DIR_S),$(SRC))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -I $(DIR_H) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx-linux
	gcc -o $(NAME) -I $(DIR_H) $(OBJS) $(CFLAGS) -lmlx -L./minilibx-linux -lbsd -lXext -lX11 -lm

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	fclean all

.PHONY: clean fclaen all re 

