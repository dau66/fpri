CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_ptr_base_x.c ft_itoa.c ft_printf.c ft_ptr_base.c ft_putstr_fd.c ft_strdup.c ft_tolower_all.c ft_usefs1.c ft_usefs.c ft_usefs2.c
OBJ = $(SRC:.c=.o)

LIB = libftprintf.a

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re