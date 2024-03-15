NAME = philo

SRCS = main.c utils.c input.c init.c program.c checker.c philo_actions.c

OBJS = $(SRCS:.c=.o)


CC = gcc

CFLAGS	= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	$(CC) $(CFGLAGS) $(OBJS) -o $(NAME)

all:	$(NAME) 

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

git:
	make fclean
	git add .
	git commit -m "update"
	git push

re: fclean all