# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 14:35:13 by tpereira          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/07/07 13:30:42 by tpereira         ###   ########.fr        #
=======
#    Updated: 2021/07/06 21:01:18 by tpereira         ###   ########.fr        #
>>>>>>> 24ffd4297d38cfe21a578624e8da92bafa666f94
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
CC 			= gcc
CFLAGS 		= -Wall -Wextra 
#-Werror
SRCS 		= $(wildcard ./srcs/*.c)
LIB_SRCS	= mv $(LIB_NAME)/libft.a ./$(NAME)
OBJS 		= $(SRCS:.c=.o)
LIB_OBJS	= $(LIB_SRCS:.c=.o)
LIB_NAME	= libft
LIB_HEADER	= -I libft/includes
INC_PATH 	= includes $(LIB_HEADER)

.c.o:
	$(CC) -g $(CFLAGS) -c $^ -o $(<:.c=.o) -I $(INC_PATH)

all:        $(NAME)

$(NAME):	$(OBJS)
	make -C $(LIB_NAME)
	mv $(LIB_NAME)/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIB_NAME)/
	rm -f $(OBJS)
fclean:     clean
	make fclean -C $(LIB_NAME)/
	rm -f $(NAME)
re:         fclean all

cc: 
<<<<<<< HEAD
	$(CC) $(CFLAGS) -g -pthread main_15.c libftprintf.a -o a.out && ./a.out 
=======
	$(CC) $(CFLAGS) -g main_15.c libftprintf.a -o a.out && ./a.out 
>>>>>>> 24ffd4297d38cfe21a578624e8da92bafa666f94

.PHONY: bonus re fclean clean all
