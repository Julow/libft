# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 13:05:11 by jaguillo          #+#    #+#              #
#    Updated: 2014/11/03 13:05:13 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

H_DIR = ./
C_DIR = ./
O_DIR = o/

C_FILES = $(shell ls -1 | grep "ft_" | grep ".c")

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rc $@ $^ && echo "	\033[1;30m-->>    \033[0;32m$@\033[0;0m" || echo "\033[0;31m$@\033[0;0m"

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc -Wall -Wextra -Werror -I$(H_DIR) -o $@ -c $< && echo "\033[0;0m$<		\033[1;30m-->>	\033[0;32m$@\033[0;0m" || (echo "\033[0;0m$<		\033[1;30m-->>	\033[0;31m$@\033[0;0m" && exit 1)

clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re: fclean all

.PHONY: all clean fclean re
