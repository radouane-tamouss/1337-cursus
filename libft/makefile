push:
	git add .
	git commit -m 'hello'
	git push

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = *.c
OBJS = $(SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME) : $(OBJS)
	ar $(NAME) $(OBJS)


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
