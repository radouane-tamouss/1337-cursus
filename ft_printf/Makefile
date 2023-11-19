CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ../libft
INCLUDES = -I$(LIBFT)

all: ft_printf

ft_printf: main.o
	$(CC) $(CFLAGS) -o ft_printf main.o $(LIBFT)/libft.a

main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c

clean:
	rm -f *.o

fclean: clean
	rm -f ft_printf

re: fclean all