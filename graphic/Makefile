##
## Makefile for makefile in /home/thibaut.lopez/Lem-In/graphic
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Mon Apr 28 11:58:44 2014 Thibaut Lopez
## Last update Tue Apr 29 00:18:33 2014 Thibaut Lopez
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
		quarter.c

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
