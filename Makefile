CC = gcc
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

SOURCE = main.c verif.c get_next_line.c \

HEADER = fillit.h

OFILE = $(SOURCE:.c=.o)

NAME = fillit

all: $(NAME)

$(NAME): $(OFILE)

%.o: %.c $(HEADER)
	make -C ./libft
	$(CC) $(CFLAGS) $(SOURCE) libft/libft.a -o $(NAME)

clean:
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all
