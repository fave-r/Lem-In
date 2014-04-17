##
## Makefile for Makefile in /home/thibaud/rendu/Piscine-C-lib/my
## 
## Made by thibaud
## Login   <thibaud@epitech.net>
## 
## Started on  Mon Oct 21 09:07:38 2013 thibaud
## Last update Thu Apr 17 05:56:37 2014 thibaud
##

FLAGS	= -W -Wall -Werror

RM	= rm -f

RMO	= rm *.o

CC	= gcc -W -Wall -Werror

NAME	= lem_in

SRCS	= main.c \
	graphe_fct.c \
	dijkstra.c \
	print.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) :	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) -W -Werror -Wall -lm
	$(RMO)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) *~

re: fclean all
