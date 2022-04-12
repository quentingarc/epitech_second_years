##
## EPITECH PROJECT, 2021
## B-CNA-410-BDX-4-1-trade-sergiu.hincu
## File description:
## Makefile
##

NAME    =       trade

SRC     =       src/main.cpp	\
				src/trade.cpp \
				src/executive.cpp \
				src/settings.cpp \
				src/update.cpp \
				src/sell_buy.cpp

OBJ     =       $(SRC:.cpp=.o)

CPPFLAGS	=	-I./include

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)
	rm -f *.gcc*

fclean: clean
	rm -f $(NAME)
	rm -f *.gcc*

re:	fclean all