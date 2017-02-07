## makefile for make in /home/jordan.roucom/CPool_rush3
## 
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
## 
## Started on  Sat Oct 29 17:09:21 2016 romain pillot
## Last update Tue Feb  7 20:04:40 2017 romain pillot
##

CC	=	gcc

NAME	=	navy

RM	=	rm -f

SRCS	=	src/main.c		\
		src/ship_loader.c	\
		src/data_handler.c	\
		src/display.c		\
		src/cell.c

LIBS	=	-Llib -lgnl

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Iinclude #-Werror -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
