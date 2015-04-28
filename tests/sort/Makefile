# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juloo <juloo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/27 15:05:13 by juloo             #+#    #+#              #
#    Updated: 2015/04/28 17:08:05 by juloo            ###   ########.fr        #
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

test: all sort rev rand dupp

sort:
	@echo " -----> Sorted <-----"
	@./$(NAME) a
	@./$(NAME) a b
	@./$(NAME) a b c
	@./$(NAME) a b c d
	@./$(NAME) a b c d e f g h i j
	@./$(NAME) a b c d e f g h i j k l m n o p q r s t u v w x y z
	@./$(NAME) `ls /bin`

rev:
	@echo " -----> Reversed <-----"
	@./$(NAME) d c
	@./$(NAME) d c b
	@./$(NAME) d c b a
	@./$(NAME) j i h g f e d c b a
	@./$(NAME) z y x w v u t s r q p o n m l k j i h g f e d c b a
	@./$(NAME) `ls -r /bin`

rand:
	@echo " -----> Random <-----"
	@./$(NAME) `seq 1 3 | shuf`
	@./$(NAME) `seq 1 5 | shuf`
	@./$(NAME) `seq 1 10 | shuf`
	@./$(NAME) `seq 1 20 | shuf`
	@./$(NAME) `seq 1 100 | shuf`
	@./$(NAME) `ls -r /bin | shuf`

big:
	@echo " -----> Big <-----"
	@./$(NAME) `ls -R /usr | shuf`
	@./$(NAME) `ls -R / 2>&1 | head -n 50000 | shuf`

dupp:
	@echo " -----> Dupplicate <-----"
	@./$(NAME) `seq 0 2`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}
	@./$(NAME) `seq 0 10`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}
	@./$(NAME) `seq 0 15`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}
	@./$(NAME) `seq 0 15`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}

.PHONY: all clean fclean re
