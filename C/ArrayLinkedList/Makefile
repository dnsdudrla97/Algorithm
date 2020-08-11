ARRAYLINKEDLISTPATH = LinkedList/
ARRAYLINKEDLISTFILES = ArrayLinkedList.c Member.c
ARRAYLINKEDLIST = $(addprefix $(ARRAYLINKEDLISTPATH), $(ARRAYLINKEDLISTFILES))

SRCPATH = ./src/
SRCFILES = main_test.c $(ARRAYLINKEDLIST)
SRCS = $(addprefix $(SRCPATH), $(SRCFILES))

OBJECTS = $(SRCS:.c=.o)

INC = -I./include/

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INC)

NAME = main_test
RM = rm -rf

.c .o :
		$(CC) $(CFLAGS) -C
all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
		@make clean


clean :
		$(RM) $(OBJECTS) core

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : re fclean celan all
