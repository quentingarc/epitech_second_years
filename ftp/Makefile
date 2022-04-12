##
## EPITECH PROJECT, 2021
## B-NWP-400-BDX-4-1-myftp-quentin.garcia
## File description:
## Makefile
##

include sources.mk

OBJ	=	$(SRC:.c=.o) 

ERROR	=	-Wall -Wextra

CFLAGS	=	-I./include

NAME	=	myftp

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(ERROR)  $(CFLAGS)

all:	$(NAME)

clean:
		rm -f $(OBJ)
		rm -f $(NAME)
		@rm -f include/*.h~
		@rm -f src/*.c~

fclean: 	clean
		rm -f $(NAME)

re:	fclean all