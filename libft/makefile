CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c    ft_isalnum.c ft_isdigit.c ft_memcmp.c  ft_strchr.c  ft_strlcat.c ft_strncmp.c ft_substr.c \
ft_bzero.c   ft_isalpha.c ft_isprint.c ft_memcpy.c  ft_strdup.c  ft_strlcpy.c ft_strnstr.c ft_tolower.c \
ft_calloc.c  ft_isascii.c ft_memchr.c  ft_memset.c  ft_strjoin.c ft_strlen.c  ft_strrchr.c ft_toupper.c ft_split.c ft_itoa.c \
ft_strtrim.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strmapi.c ft_memmove.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: ${BOBJS}
	ar rcs ${NAME} ${BOBJS}

clean:
	rm -rf $(OBJS)
	rm -rf $(BOBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re


push:
	cd .. && \
	git add . && \
	git commit -m 'push o ssf' && \
	git push
