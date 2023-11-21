CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf
LIBFT = ../libft
LIBFT_LIB = $(LIBFT)/libft.a
SRC = main.c ft_putnbr_x.c
INCLUDES = -I$(LIBFT)
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT)

$(NAME) : $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT) -lft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	rm -rf $(OBJ)
	make -C $(LIBFT) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re : fclean all

.PHONY : all clean fclean re