##
## Makefile for makefile in /home/thibaut.lopez/Lem-In/graphic
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Mon Apr 28 11:58:44 2014 Thibaut Lopez
## Last update Fri May  2 20:13:13 2014 Thibaut Lopez
##

CC=		gcc

RM=		rm -f

CFLAGS	+=	-Wextra -Wall -Werror -I. -lm -lSDL -lGL -lGLU -g3

NAME=		ant_colony

SRCS=		init_graphic.c \
		init_tubes.c \
		list_fun.c \
		move_ants.c \
		operate_event.c \
		draw_fun/draw_circle.c \
		draw_fun/draw_line.c \
		draw_fun/draw_tubes.c \
		draw_fun/line.c \
		draw_fun/pixel_fun.c \
		draw_fun/quarter2.c \
		draw_fun/quarter.c \
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
		parsing/xfunction.c \
		parsing/ants.c

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -lm -g3

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME) *~

re:		fclean all

.PHONY:		all fclean re
