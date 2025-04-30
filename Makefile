##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CFLAGS = -W -Wextra -Wall

CPPFLAGS = -I ./include

SRC = $(shell find -name "*.c")

OBJ = $(SRC:.c=.o)

NAME = hangman

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
