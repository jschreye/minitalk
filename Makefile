# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 13:15:32 by jschreye          #+#    #+#              #
#    Updated: 2022/01/04 15:02:32 by jschreye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME1 = server

NAME2 = client

all: 
		make -C libft
		$(CC) $(CFLAGS) serveur.c libft/libft.a -o $(NAME1)
		$(CC) $(CFLAGS) client.c libft/libft.a -o $(NAME2)

clean:
		make clean -C libft
		rm -rf client.o serveur.o

fclean: clean
		make fclean -C libft
		rm -rf $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
