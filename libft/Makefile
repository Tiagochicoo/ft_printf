# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 22:20:21 by tpereira          #+#    #+#              #
#    Updated: 2022/05/18 23:45:04 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH = -Iincludes
SRCS     = $(wildcard ./srcs/*.c)
OBJS     =  $(SRCS:.c=.o)
NAME     =  libft.a
SO       =    libft.so
CFLAGS   = -Wall -Werror -Wextra -g -fPIC

.c.o:
	@$(CC) $(CFLAGS) -c $^ -o $(<:.c=.o) $(INC_PATH)
all:		$(NAME)
so:			$(SO)
$(NAME):	$(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@printf "\e[1;34m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[1;34m█▓▒░	     Compiled Libft	     ░▒▓█ \e[0m\n"
	@printf "\e[1;34m ╚════════════════════════════════════╝\e[0m\n"
$(SO):		$(OBJS)
	@gcc -shared -o $(SO) $^
clean:
	@rm -f ./srcs/*.o
	@printf "\e[31;5;200m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[31;5;200m░▒▓█         Cleaned Libft  	    █▓▒░\e[0m\n"
	@printf "\e[31;5;200m ╚════════════════════════════════════╝\e[0m\n"
soclean:    clean
	@rm -f $(SO)
fclean:
	@rm -f $(NAME)
	@rm -f $(SO)
re:		clean fclean all

.PHONY: so bonus re fclean soclean clean all
