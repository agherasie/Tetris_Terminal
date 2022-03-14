##
## EPITECH PROJECT, 2022
## Tetris
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME =	tetris
CFLAGS += -g3
LIB += -Llib -lmy -Iinclude/
NCURSES += -lncurses

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	gcc -o $(NAME) $(SRC) $(LIB) $(NCURSES) $(CFLAGS)
	rm -f $(shell find -name '*.o')

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f vgcore.*
	make fclean -C lib/

re:	fclean all

auteur:
	echo $(USER) > auteur
