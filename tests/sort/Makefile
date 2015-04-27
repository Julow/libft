# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juloo <juloo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/27 15:05:13 by juloo             #+#    #+#              #
#    Updated: 2015/04/27 19:04:21 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_sort.exe
FLAGS = -Wall -Wextra -I ../.. -g

all: $(NAME)

$(NAME): test_sort.c libft
	clang $(FLAGS) $< -o $@ -L ../.. -lft

libft:
	@make -C ../.. debug

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

test: all
	@echo Small sorted
	@./$(NAME) a b c d
	@./$(NAME) a b c d e f g h i j
	@./$(NAME) a b c d e f g h i j k l m n o p q r s t u v w x y z
	@echo Small Reversed
	@./$(NAME) d c b a
	@./$(NAME) j i h g f e d c b a
	@./$(NAME) z y x w v u t s r q p o n m l k j i h g f e d c b a
	@echo Small Random
	@./$(NAME) a z e r
	@./$(NAME) a z e r t y u i o p
	@./$(NAME) a z e r t y u i o p q s d f g h j k l m w x c v b n
	@echo Big sorted
	@./$(NAME) `ls -R /usr`
	@echo Big Reversed
	@./$(NAME) `ls -Rr /usr`
	@echo Big Random
	@./$(NAME) `ls -Rt /usr`
	@./$(NAME) `ls -Rtr /usr`

.PHONY: all clean fclean re
