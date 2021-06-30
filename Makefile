# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 14:35:13 by tpereira          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/06/30 08:53:44 by tpereira         ###   ########.fr        #
=======
#    Updated: 2021/06/19 12:47:24 by tpereira         ###   ########.fr        #
>>>>>>> cad04723e131ea12c520e969def68b9014154ceb
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
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
	$(CC) $(CFLAGS) -g main_15.c libftprintf.a && ./a.out

.PHONY: bonus re fclean clean all
