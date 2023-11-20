CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf
SRC = main.c ft_putnbr_x.c
OBJ = $(SRC:.c=.o)
LIBFT = ../libft
INCLUDES = -I$(LIBFT)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all