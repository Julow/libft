# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/08/16 01:47:04 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ../.. debug
	@clang -Wall -Wextra -g -I ../.. test.c -o list_test -L ../.. -lft

clean:
	@rm -f list_test

fclean: clean

re: fclean all

test: all
	@./list_test

.PHONY: all clean fclean re test
