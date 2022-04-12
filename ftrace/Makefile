##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

include mk/source.mk

RM			=	rm -f

CC			=	gcc

CPPFLAGS	=	-I./include
CFLAGS		=	-W -Wall -Wextra -g
LDFLAGS		=	-L./lib
LDLIBS		=	-lmy

DIR_SRC		=	./src/
SRC_MAIN	=	main.c

OBJ_SRC		=	$(addprefix $(DIR_SRC), $(SRC:.c=.o))
OBJ_MAIN	=	$(addprefix $(DIR_SRC), $(SRC_MAIN:.c=.o))

$(BINARY_NAME):	lib $(OBJ_SRC) $(OBJ_MAIN)
	$(CC) $(OBJ_SRC) $(OBJ_MAIN) -o $@ $(LDFLAGS) $(LDLIBS)


all:	$(BINARY_NAME)

lib:
	$(MAKE) -C lib/my

clean:
	$(RM) $(OBJ_SRC) $(OBJ_MAIN)
	$(MAKE) -C ./lib/my $@

fclean:	clean
	$(RM) $(BINARY_NAME)
	$(MAKE) -C ./lib/my $@
	$(MAKE) -C ./tests/ $@

tests_run:
	$(MAKE) -C ./tests

gcovr:
	gcovr --exclude tests --branches
	gcovr --exclude tests

re:	fclean all

.PHONY:	$(BINARY_NAME) all clean fclean tests_run re lib