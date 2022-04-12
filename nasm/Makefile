##
## EPITECH PROJECT, 2020
## B-PSU-400-BDX-4-1-malloc-quentin.garcia
## File description:
## makefile
##

SRC	=	src/strlen.asm \
		src/strchr.asm \
		src/memset.asm \
		src/memcpy.asm \
		src/strcmp.asm \
		src/strncmp.asm \
		src/strcasecmp.asm 

NAME	 =	libasm.so

OBJ	=	$(SRC:.asm=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		ld -shared $(OBJ) -o $(NAME)

%.o	:	%.asm
	nasm -f elf64 -o $@ $<

clean:
	rm -rf $(OBJ)

fclean:        clean
	rm -rf $(NAME)

re:	fclean all