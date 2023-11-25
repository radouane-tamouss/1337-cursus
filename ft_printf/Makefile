CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c ft_putnbr_fd.c ft_strchr.c ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_x.c ft_isalpha.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean: 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re