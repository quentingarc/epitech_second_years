##
## EPITECH PROJECT, 2021
## B-OOP-400-BDX-4-1-arcade-quentin.garcia
## File description:
## Makefile
##



NAME		= arcade

SRCS		= source/main.cpp	\
			source/Core.cpp	\
			source/weigh.cpp	\

CFLAGS	=  include -W -Wall -Wextra

all: core

core:
	g++ -o $(NAME) $(SRCS) -I $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re core