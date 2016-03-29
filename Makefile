##
## Makefile for 109titration in /home/VEYSSI_B/rendu/Maths/109titration
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Tue Mar 29 15:01:55 2016 Baptiste veyssiere
## Last update Tue Mar 29 15:13:37 2016 Baptiste veyssiere
##

NAME	= 109titration

CC	= gcc

RM	= rm -f

LDFLAGS	= -lm

CFLAGS	= -I./include

SRCS	= src/109titration.c	\
	  src/calc.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
