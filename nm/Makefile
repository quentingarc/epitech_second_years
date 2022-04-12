##
## EPITECH PROJECT, 2021
## B-PSU-400-BDX-4-1-nmobjdump-quentin.garcia
## File description:
## Makefile
##

SRC1	=	obj-dump/src/main.c  \
			obj-dump/src/establishes.c \
			obj-dump/src/objdump_64.c \
			obj-dump/src/flag_64.c \
			obj-dump/src/flag_32.c \
			obj-dump/src/objdump_32.c

SRC2	=	nmy/src/main.c 	\
			nmy/src/establishes.c

OBJ		=	$(SRC1:.c=.o)

OBJ1	=	$(SRC2:.c=.o)

CFLAGS    =    -I./include

NAME    =    my_nm

SD_NAME    =    my_objdump

all:    $(NAME) $(SD_NAME)

nm: $(NAME)

objdump: $(SD_NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC2) $(CFLAGS)

$(SD_NAME):	$(OBJ1)
	gcc -o $(SD_NAME) $(SRC1) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)
	rm -f $(SD_NAME)
	rm -f *.gcda *.gno *.gcno

re:       fclean all
