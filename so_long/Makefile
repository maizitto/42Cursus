
NAME = so_long

SRCS = main.c maps.c game.c path.c close.c tile.c hooks.c enemy.c visual.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FTPRINTF = printf/

CFLAGS	= -Wall -Wextra -Werror
MFLAGS	= -lmlx -framework OpenGL -framework AppKit

$(NAME) : $(OBJS)
	@ make -C $(FTPRINTF)
	@ make -C ./mlx
	cp ./mlx/libmlx.dylib .
	${CC} ${CFLAGS} ${OBJS} ${MFLAGS} -o ${NAME} printf/libftprintf.a

all:	$(NAME)

clean:
	@make clean -C $(FTPRINTF)
	@make clean -C ./mlx
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(FTPRINTF)
	@rm -f libmlx.dylib
	@rm -f $(NAME)

git:
	git add .
	git commit -m "update"
	git push

re: fclean all