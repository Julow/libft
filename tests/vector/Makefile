# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/08/23 15:16:59 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ../..
	@clang -Wall -Wextra -O2 -I ../.. test.c -o vector_test -L ../.. -lft

clean:
	@rm -f vector_test

fclean: clean

re: fclean all

test: all
	@./vector_test

.PHONY: all clean fclean re test
