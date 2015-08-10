# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/08/10 15:11:11 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ../..
	clang -Wall -Wextra -I ../.. test.c -o eval_expr -L ../.. -lft -lm

clean:
	@rm -f eval_expr

fclean: clean

re: fclean all

test: all
	@./eval_expr "5" 5
	@./eval_expr "(5)" 5
	@./eval_expr "(((5)))" 5
	@./eval_expr "1 + 3" 4
	@./eval_expr "1 + 3 * 2" 7
	@./eval_expr "(1 + 3) * 2" 8
	@./eval_expr "3^2" 9
	@./eval_expr "2 * 9 * 4" 72
	@./eval_expr "2 * 3^2 * 4 + 1" 73
	@./eval_expr "(2 * 3)^2 * 4" 144
	@./eval_expr "36 * 4" 144
	@./eval_expr "36 % 5" 1
	@./eval_expr "sqrt 5^2" 5
	@./eval_expr "sqrt 5.8^2" 5.8
	@./eval_expr "(sqrt 5.8)^2" 5.8
	@./eval_expr "abs -5" 5
	@./eval_expr "abs (-5)" 5
	@./eval_expr "abs(-5)" 5
	@./eval_expr "abs-5" 5
	@./eval_expr "abs-5.3" 5.3
	@./eval_expr "-5.3" -5.3
	@./eval_expr "-5 + 0.3" -4.7
	@./eval_expr "2 / 0"
	@./eval_expr "0-(2 / 0)"
	@./eval_expr "cos 0" 1

.PHONY: all clean fclean re test
