##
## Makefile for Makefile in /home/thibaud/rendu/Piscine-C-lib/my
##
## Made by thibaud
## Login   <thibaud@epitech.net>
##
## Started on  Mon Oct 21 09:07:38 2013 thibaud
## Last update Sun Apr 20 19:30:10 2014 alex-odet
##

CC=	gcc

RM=	rm -f

CFLAGS	+=	-Wextra -Wall -Werror -I.

NAME	= lem_in

SRCS	= main.c \
	graphe_fct.c \
	dijkstra.c \
	print.c \
	lib.c \
	lib_next.c \
	graph_fct_next.c \
	get_ways.c \
	run_lem_in.c \
	free.c \
	parsing/error.c \
	parsing/my_len_tab.c \
	parsing/my_put_in_lem_list.c \
	parsing/parser.c \
	parsing/xfunction.c \
	parsing/get_next_line.c \
	parsing/my_list_size.c \
	parsing/my_str_to_wordtab.c \
	parsing/parser_next.c \
	parsing/my_strchr.c

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
