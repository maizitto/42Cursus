NAME = push_swap

NAME_BONUS = checker

SRCS = main.c init_stack.c close.c sorting.c maxmin.c sort.c sort_aux.c moves.c \
		moves/swap.c moves/rotate.c moves/revrotate.c moves/push.c \
		vars/ft_split.c vars/ft_atoi.c vars/ft_isdigit.c vars/ft_strdup.c

OBJS = $(SRCS:.c=.o)

BSRCS = ./bonus/main.c ./vars/ft_split.c ./vars/ft_atoi.c ./vars/ft_isdigit.c ./vars/ft_strdup.c \
		./init_stack.c ./close.c ./bonus/moves_bonus/swap_bonus.c ./bonus/moves_bonus/rotate_bonus.c \
		./bonus/moves_bonus/revrotate_bonus.c ./bonus/moves_bonus/push_bonus.c \
		./maxmin.c ./bonus/gnl/get_next_line.c ./bonus/gnl/get_next_line_utils.c ./bonus/input.c

BOBJS = $(BSRCS:.c=.o)

CC = gcc

CFLAGS	= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	@ make -C printf/
	$(CC) $(CFGLAGS) $(OBJS) -o $(NAME) printf/libftprintf.a

bonus : $(BOBJS)
	@ touch $@
	@ make -C ./printf/
	$(CC) $(CFGLAGS) $(BOBJS) -o $(NAME_BONUS) ./printf/libftprintf.a

all:	$(NAME) bonus

clean:
	@make clean -C printf/
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@make fclean -C printf/
	@rm -f $(NAME) $(NAME_BONUS)

git:
	make fclean
	git add .
	git commit -m "update"
	git push

re: fclean all