NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
INCLUDES = -I/usr/include -Imlx

# System-specific variables
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    LDFLAGS = -Lmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
    MLX_VERSION_DIR = mlx-versions/mlx-linux
    MLX_LIB = libmlx.a
else ifeq ($(UNAME_S),Darwin)
    LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
    MLX_VERSION_DIR = mlx-versions/mlx-mac
    MLX_LIB = libmlx.dylib
endif

MLX_DIR = mlx/
MLX_PATH = $(MLX_DIR)$(MLX_LIB)

.PHONY: all clean fclean re git prepare_mlx ascii_art

all: prepare_mlx $(NAME) ascii_art

prepare_mlx:
	@rm -rf $(MLX_DIR)
	@mkdir -p $(MLX_DIR)
	@cp -r $(MLX_VERSION_DIR)/* $(MLX_DIR)
	@if [ "$(UNAME_S)" = "Linux" ]; then \
		(cd $(MLX_DIR) && ./configure && $(MAKE)); \
	elif [ "$(UNAME_S)" = "Darwin" ]; then \
		(make -C $(MLX_DIR)); \
	fi

ascii_art:
	@echo "\033[1;34m ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ \033[0m"
	@echo "\033[1;35m██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\033[0m"
	@echo "\033[1;36m██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\033[0m"
	@echo "\033[1;34m██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\033[0m"
	@echo "\033[1;35m╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝\033[0m"
	@echo "\033[1;36m ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ \033[0m"

SRCS = cub3d.c \
		src/errors.c \
		src/utils/split.c src/utils/utils.c \
		src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
		src/init/init_struct.c src/init/init_struct2.c src/init/init_game.c src/init/init_engine.c \
		src/validator/file_function.c src/validator/flood.c src/validator/parser.c src/validator/validate_map.c

OBJS = $(SRCS:%.c=obj/%.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf obj
	@if [ "$(UNAME_S)" = "Linux" ]; then \
		(cd $(MLX_DIR) && $(MAKE) clean); \
	elif [ "$(UNAME_S)" = "Darwin" ]; then \
		(make clean -C $(MLX_DIR)); \
		rm -rf $(MLX_DIR)mlx_image.swiftsourceinfo; \
		rm -rf $(MLX_DIR)mlx_init.swiftsourceinfo; \
		rm -rf $(MLX_DIR)mlx_window.swiftsourceinfo; \
	fi

fclean: clean
	@rm -f libmlx.dylib
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)

git:
	make fclean
	git add .
	git commit -m "update"
	git push

re: fclean all
