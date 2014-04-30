##
## Makefile for makefile in /home/thibaut.lopez/Lem-In/graphic
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Mon Apr 28 11:58:44 2014 Thibaut Lopez
## Last update Wed Apr 30 16:52:50 2014 Thibaut Lopez
##

CC=		gcc

RM=		rm -f

CFLAGS	+=	-Wextra -Wall -Werror -I. -lSDL -lGL -lGLU -lm

NAME=		ant_colony

SRCS=		draw_circle.c \
		draw_line.c \
		draw_tubes.c \
		init_graphic.c \
		line.c \
		operate_event.c \
		quarter2.c \
		quarter.c \
		parsing/arc_num.c \
		parsing/bad_arc.c \
		parsing/error.c \
		parsing/fill_num_list.c \
		parsing/free_list.c \
		parsing/init.c \
		parsing/my_len_tab.c \
		parsing/my_list_size.c \
		parsing/my_put_in_arc_list.c \
		parsing/my_put_in_lem_list.c \
		parsing/my_strchr.c \
		parsing/my_strscat.c \
		parsing/my_str_to_wordtab.c \
		parsing/parse_arc.c \
		parsing/parse.c \
		parsing/parser.c \
		parsing/parser_next.c \
		parsing/xfunction.c

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME) *~

re:		fclean all

.PHONY:		all fclean re
