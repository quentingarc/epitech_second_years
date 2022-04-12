##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

CPPFLAGS	=	-Wall -Wextra -I./include -g
##--coverage

CC	=	g++

SRC	=	src/Parser.cpp	\
		main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	nanotekspice


$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)
	rm -f *.gcc*

fclean: clean
	rm -f $(NAME)
	rm -f ./unit_tests
	rm -f *.gcc*

re:	fclean all

.PHONY:		all fclean clean re $(NAME)