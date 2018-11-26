#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 14:02:30 by nlavrine          #+#    #+#              #
#    Updated: 2018/11/17 14:02:31 by nlavrine         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) *.c -L./libft -lft -g

fclean:
	@rm -f $(NAME)

re: fclean $(NAME)