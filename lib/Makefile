##
## EPITECH PROJECT, 2022
## tetris
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME =	libmy.a
CFLAGS += -Wextra -Iinclude

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../include/
	rm -f $(shell find -name '*.o')

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
