# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/08/23 14:03:29 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ../.. debug
	@clang -Wall -Wextra -I ../.. test.c -o vector_test -L ../.. -lft

clean:
	@rm -f vector_test

fclean: clean

re: fclean all

test: all
	@./vector_test

.PHONY: all clean fclean re test
