##
## EPITECH PROJECT, 2021
## B-NWP-400-BDX-4-1-myteams-teo.martos
## File description:
## Makefile
##

CLIENT    =		client/main.c				\
				client/print_users.c		\
				client/init_client.c		\
				client/login_events.c		\
				client/client.c

SERVER	=		server/main.c				\
				server/server.c				\
				server/ptr.c				\
				server/save_users.c			\
				server/get_user_id.c		\
				server/logout_server.c		\
				server/logout_client.c		\
				server/init_server.c

LIB		=		lib/my_put_nbr.c			\
				lib/my_putchar.c			\
				lib/my_flags.c				\
				lib/my_printf.c				\
				lib/my_strncat.c			\
				lib/my_putstr.c				\
				lib/get_client_fd.c			\
				lib/init_list.c				\
				lib/my_strcat.c				\
				lib/get_user_index.c		\
				lib/my_str_to_word_array.c


OBJ_SERVER    =    $(SERVER:.c=.o) $(LIB:.c=.o)

OBJ_CLIENT	=	$(CLIENT:.c=.o) $(LIB:.c=.o)

CFLAGS    =	-I ./include -I ./libs/myteams

LDFLAGS =	-L./libs/ -lmyteams

NAME_SERVER    =    myteams_server

NAME_CLIENT	=	myteams_cli

all:	$(NAME_SERVER) $(NAME_CLIENT)

server:		$(NAME_SERVER)

client:	$(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER)
	gcc -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS) $(LDFLAGS) -luuid

$(NAME_CLIENT):	$(OBJ_CLIENT)
	gcc -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS) $(LDFLAGS) -luuid

clean:
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)

fclean:    clean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)
	rm -f *.gcda *.gno *.gcno
	rm -f unit_tests

re:   	fclean all