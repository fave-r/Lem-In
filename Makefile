##
## Makefile for Makefile in /home/thibaud/rendu/Piscine-C-lib/my
##
## Made by thibaud
## Login   <thibaud@epitech.net>
##
## Started on  Mon Oct 21 09:07:38 2013 thibaud
## Last update Thu Apr 17 16:41:43 2014 romaric
##

CC=	gcc

RM=	rm -f

CFLAGS	+=	-Wextra -Wall -Werror

NAME	= lem_in

SRCS	= main.c \
	graphe_fct.c \
	dijkstra.c \
	print.c \
	lib.c \
	lib_next.c \
	graph_fct_next.c

OBJS=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME) :	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) *~

re:	fclean all

.PHONY:	all fclean re
