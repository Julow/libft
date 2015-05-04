# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juloo <juloo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/04 01:24:25 by juloo             #+#    #+#              #
#    Updated: 2015/05/04 01:53:22 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_hmap

all: $(NAME)

$(NAME):
	@make -C ../.. debug
	clang -o test_hmap test_hmap.c -I../.. -L../.. -lft

clean:
	@rm -f test_hmap

fclean: clean

test: all
	./test_hmap

re: fclean all

.PHONY: all clean fclean test re
