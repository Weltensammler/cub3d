NAME = cub3d

CC = gcc

CFLAGS	= #-Wall -Werror -Wextra
LIBFT	= ./library/Libft
GNL		= ./library/gnl
LIB_LIB	= $(LIBFT)/libft.a
GNL_LIB	= $(GNL)/gnl.a
SRC		= ./src/
MAP		= ./map/
# UNAME = $(shell uname)

# ifeq ($(UNAME), Darwin)
# 	MLX	= ./mlx_linux
# 	MLX_LIB	= mlx_linux/libmlx_Linux.a
# else
# 	MLX	= ./mlx_linux
# 	MLX_LIB	= mlx_linux/libmlx_Linux.a
# endif

FILES = 	main.c \
			$(SRC)check_input_argv.c \
			$(SRC)init_struct.c \
			$(MAP)map.c \
			$(MAP)check_map.c \


OBJS =		$(FILES:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			# make -C $(MLX)
			make bonus -C $(LIBFT)
			make -C $(GNL)
			$(CC) $(CFLAGS) $(OBJS) $(LIB_LIB) $(GNL_LIB) -o $@

clean:
			make clean -C $(LIBFT)
			make clean -C $(GNL)
			rm -f $(OBJS)

fclean:	clean
			make fclean -C $(LIBFT)
			make fclean -C $(GNL)
			rm -f $(NAME)

re:		fclean all
