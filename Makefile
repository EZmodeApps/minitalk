# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caniseed <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:48:59 by caniseed          #+#    #+#              #
#    Updated: 2021/08/11 22:35:37 by caniseed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk

SERVER	= server.c
CLIENT	= client.c

OBJS	= client.o server.o

LIBFT	= libft/libft.a

HEADER	= minitalk.h

all:	$(NAME)

$(NAME):
	make -C libft
	gcc -Wall -Wextra -Werror $(SERVER) $(LIBFT) -o server
	gcc -Wall -Wextra -Werror $(CLIENT) $(LIBFT) -o client

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean:	 clean
	make fclean -C libft
	rm -f server client

re:	fclean all

.PHONY:	all clean fclean re
