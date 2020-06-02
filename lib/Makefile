##
## EPITECH PROJECT, 2019
## lib_uni
## File description:
## Makefile
##

NAME			=			libmy.a

IDIR			=			include/

SRC				=			$(wildcard lib/*.c)

OBJ				=			$(SRC:.c=.o)
OBJ_LK			=			$(SRC_LK:.c=.o)

CFLAGS			+=			-I$(IDIR)
CFLAGS			+=			-g
CFLAGS			+=			-Wall -Wextra

.PHONY: all fclean re

.SILENT:
all: $(NAME)

$(NAME):	$(OBJ)
		ar rc -o $(NAME) $(OBJ)
		rm -f $(OBJ) $(OBJ_LK)
		echo "library compiling..."

fclean:
		rm -f $(NAME)

re: fclean all
