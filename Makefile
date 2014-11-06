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

C_FILES = $(shell ls -1t | grep "ft_" | grep ".c")

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

all: $(NAME)

$(NAME): $(O_FILES)
	@echo $@
	@ar rc $@ $^

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@echo "$<	-->>	$@"
	@gcc -Wall -Wextra -Werror -I$(H_DIR) -o $@ -c $<

clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re: fclean all

.PHONY: all clean fclean re
