# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/08/23 12:17:15 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ../.. debug
	@clang -Wall -Wextra -g -I ../.. test.c -o deque_test -L ../.. -lft

clean:
	@rm -f deque_test

fclean: clean

re: fclean all

test: all
	@./deque_test

.PHONY: all clean fclean re test
