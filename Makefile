NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -Llibft -L./minilibx-linux/ -O2 -lft -lm -lmlx -lXext -lX11 -lpthread 
SRCS = srcs/main.c \
       srcs/hook.c \
       srcs/mandelbrot.c \
       srcs/julia.c \
       srcs/utils.c \
       srcs/burning.c 

OBJS = $(SRCS:.c=.o)

HEADER = includes/fractol.h

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft/

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re

