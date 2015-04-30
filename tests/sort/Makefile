# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juloo <juloo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/27 15:05:13 by juloo             #+#    #+#              #
#    Updated: 2015/04/30 23:19:37 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_sort.exe
FLAGS = -Wall -Wextra -I ../.. -g

SHELL = /bin/bash

all: $(NAME)

$(NAME): test_sort.c libft
	clang $(FLAGS) $< -o $@ -L ../.. -lft

libft:
	@make -C ../.. debug

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

test: all sort rev frand rand dupp

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

frand:
	@echo " -----> Fix random <-----"
	@./$(NAME) g u o j
	@./$(NAME) m n v i r
	@./$(NAME) d g m c r a k
	@./$(NAME) w b n p h q t l i z e o c x
	@./$(NAME) n d l c m e g j o y w t k i b p a u h q r z f x s v
	@./$(NAME) t p u e d m k a j v h z b x f r y s c l o g i w q n
	@./$(NAME) x t j d k u e g y l a r c n f z h i q o s p b m w v

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
	@./$(NAME) `echo \`seq 0 15\`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,} | shuf`
	@./$(NAME) `echo \`seq 0 10\`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,} | shuf`

.PHONY: all clean fclean re
