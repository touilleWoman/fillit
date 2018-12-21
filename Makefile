CC = gcc
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

SOURCE = main.c verif.c get_next_line.c \
libft/libft.a \

HEADER = fillit.h

OFILE = $(SOURCE:.c=.o)

NAME = fillit.a

all: $(NAME)

$(NAME): $(HEADER)
	$(CC) $(SOURCE) -o $(NAME)  $(CFLAGS)

clean:
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all
