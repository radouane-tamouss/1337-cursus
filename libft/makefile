CC = cc
CFLAGS = -Wall -Wextra -Werror
# F := strlen
SRCS = ft_bzero.c ft_memset.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

push:
	cd ..
	git add .
	git commit -m 'push'
	git push
