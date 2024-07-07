NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES = -I/usr/include -Imlx_linux -O3

.PHONY: all configure_mlx

all: $(NAME) ascii_art

ascii_art:
	@echo "\033[1;34m ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ \033[0m"
	@echo "\033[1;35m██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\033[0m"
	@echo "\033[1;36m██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\033[0m"
	@echo "\033[1;34m██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\033[0m"
	@echo "\033[1;35m╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝\033[0m"
	@echo "\033[1;36m ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ \033[0m"

SRCS = cub3d.c \
		src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
		src/init.c src/parser.c src/errors.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	${CC} ${CFLAGS} ${OBJS} ${MFLAGS} -o ${NAME}

all:	$(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

git:
	git add .
	git commit -m "update"
	git push

re: fclean all