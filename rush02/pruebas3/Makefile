# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaballe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 11:54:10 by jcaballe          #+#    #+#              #
#    Updated: 2019/10/20 09:12:53 by jcaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = rush-02.c ft_putstr.c ft_putnbr.c ft_search_key.c ft_print_3_block.c ft_blocks.c ft_strlen.c ft_print_value.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
