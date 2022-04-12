##
## EPITECH PROJECT, 2021
## B-ASM-400-BDX-4-1-asmminilibc-quentin.garcia
## File description:
## makefile
##

NAME	=	libmy_malloc.so

CFLAGS	=	 -I./include

SRC	=	src/malloc.c

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		gcc $(CFLAGS) -shared -o $(NAME) $(MAIN) $(SRC)

all	:	$(NAME)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all