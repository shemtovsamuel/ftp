##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile
##

NAME		= myftp
SRC	= src/main.c \
	src/args.c \
	src/util.c \
	src/command.c \
	src/handle_client.c \
	src/call_command.c \
	src/command/help.c \
	src/command/user.c \
	src/command/pass.c \
	src/command/noop.c \
	src/command/pwd.c \
	src/command/cwd.c \
	src/command/dele.c \
	src/command/cdup.c \
	src/command/quit.c \
	src/command/pasv.c \
	src/command/port.c \

OBJ		=	$(SRC:.c=.o)
CFLAGS		:=	-Wall -Wextra
CFLAGS		+=	-iquote ./include/

all:		$(NAME)
$(NAME):	$(OBJ)
			gcc $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LFLAGS)

clean:
			$(RM) $(OBJ) *.gc*

fclean:		clean
			$(RM) $(NAME) $(UT_NAME)

re:			fclean all

.PHONY: all, tests_run, clean, fclean, re
