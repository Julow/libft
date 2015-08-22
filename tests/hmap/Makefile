# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/08/22 23:33:24 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ../.. debug
	@clang -Wall -Wextra -g -I ../.. test.c -o hmap_test -L ../.. -lft

clean:
	@rm -f hmap_test

fclean: clean

re: fclean all

test: all
	@./hmap_test

.PHONY: all clean fclean re test
