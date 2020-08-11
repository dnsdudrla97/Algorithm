NQUEENPATH = nqueen/
NQUEENFILES = nqueen.c stackIn.c
NQUEEN = $(addprefix $(NQUEENPATH), $(NQUEENFILES))

SRCPATH = ./src/
SRCFILES = main_test.c $(NQUEEN)
SRCS = $(addprefix $(SRCPATH), $(SRCFILES))

OBJECTS = $(SRCS:.c=.o)

INC = -I./include/

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INC)

NAME = main_test
RM = rm -fr

.c .o :
		$(CC) $(CFLAGS) -c

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
		@make clean

clean :
		$(RM) $(OBJECTS) core

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all