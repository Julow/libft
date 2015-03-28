# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/03/28 20:06:22 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -I ../..

all: ft_rmatch

ft_rmatch: libft
	clang $(FLAGS) reg_test.c -o $@ -L ../.. -lft

libft:
	@make -C ../..

clean:
	rm -f ft_rmatch

fclean: clean

re: fclean all

test: all
	@bash reg_test.sh
