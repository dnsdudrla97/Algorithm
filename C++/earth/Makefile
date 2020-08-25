EARTHPATH = namin/
EARTHFILES = namin.cpp
EARTH = $(addprefix $(EARTHPATH), $(EARTHFILES))

SRCPATH = ./src/
SRCFILES = main.cpp $(EARTH)
SRCS = $(addprefix $(SRCPATH), $(SRCFILES))

OBJECTS = $(SRCS:.c=.o)

INC = -I./include/

CC = g++
CFLAGS = -Wall -Werror -Wextra $(INC)

NAME = main
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