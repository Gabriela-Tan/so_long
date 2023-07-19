NAME = so_long
SRCS = 1_init_game.c \
	2_window_image_handling.c \
	3_messages.c \
	4_movement.c \
	5_error_handling1.c \
	6_error_handling2.c \
	7_free_end_game.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
FRAMEWORKS = -framework OpenGL -framework AppKit

all: lib $(NAME)

lib:
	make -C include/libft
	make -C include/minilibx

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) include/minilibx/libmlx.a include/libft/libft.a $(FRAMEWORKS)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@	

clean:
	rm -rf $(OBJS)
	make fclean -C include/libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re