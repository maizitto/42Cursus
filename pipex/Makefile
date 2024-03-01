NAME = pipex

SRCS = 	main.c utils.c ft_split.c ft_strjoin.c epur.c aux.c

BSRCS = bonus.c utils.c ft_split.c ft_strjoin.c epur.c aux.c gnl/gnl.c gnl/gnlb.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CC = gcc

CFLAGS	= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	$(CC) $(CFGLAGS) $(OBJS) -o $(NAME)

bonus:	$(BOBJS)
	$(CC) $(CFGLAGS) $(BOBJS) -o $(NAME)

all:	$(NAME) 

clean:
	@rm -f $(OBJS)
	@rm -f $(BOBJS)

fclean: clean
	@rm -f $(NAME)

git:
	make fclean
	git add .
	git commit -m "update"
	git push

re: fclean all