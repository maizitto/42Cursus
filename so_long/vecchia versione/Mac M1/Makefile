
NAME = so_long

SRCS = main.c maps.c game.c path.c close.c tile.c hooks.c enemy.c visual.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FTPRINTF = printf/

CFLAGS	= -Wall -Wextra -Werror

MLX_DIR := ./minilibx_mms_20200219/
MLX_PATH := $(MLX_DIR)libmlx.dylib
MLX	=	libmlx.dylib


$(NAME) : $(OBJS)
	@ make -C $(FTPRINTF)
	@(test -f $(MLX)) || (make -C $(MLX_DIR) && mv $(MLX_PATH) ./)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} printf/libftprintf.a $(MLX)

all:	$(NAME)

clean:
	@make clean -C $(FTPRINTF)
	@make clean -C $(MLX_DIR)
	@rm -rf $(MLX_DIR)mlx_image.swiftsourceinfo
	@rm -rf $(MLX_DIR)mlx_init.swiftsourceinfo
	@rm -rf $(MLX_DIR)mlx_window.swiftsourceinfo
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(FTPRINTF)
	@rm -f $(MLX)
	@rm -f $(NAME)

re: fclean all