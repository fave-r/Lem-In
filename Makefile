##
## Makefile for Makefile in /home/thibaud/rendu/Piscine-C-lib/my
##
## Made by thibaud
## Login   <thibaud@epitech.net>
##
## Started on  Mon Oct 21 09:07:38 2013 thibaud
## Last update Sat Apr 19 23:22:58 2014 thibaud
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
	graph_fct_next.c \
	get_ways.c \
	run_lem_in.c

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
