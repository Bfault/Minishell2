##
## EPITECH PROJECT, 2019
## PSU_minishell_2019
## File description:
## Makefile
##

NAME			=			mysh

IDIR			=			include/
IDIR_MY			=			lib/include/

LDIR			=			lib/
LNAME			=			my

SRC				=			main.c \
							$(wildcard src/*.c) \
							$(wildcard src/linked_list/*.c) \

OBJ				=			$(SRC:.c=.o)

CC				=			gcc

CFLAGS			+=			-I $(IDIR) -I $(IDIR_MY)
CFLAGS			+=			-Wall -Wextra -g

.PHONY: all clean fclean re

.SILENT:
all:	$(NAME)

$(NAME):	$(OBJ)
		make -C $(LDIR)
		$(CC) -o $(NAME) $(OBJ) -L $(LDIR) -l $(LNAME)
		echo "build..."

clean:
		rm -f $(OBJ)
		echo "Clean up done..."

fclean:	clean
		make -C $(LDIR) fclean
		rm -f $(NAME)
		echo "binary removed..."

re:	fclean all