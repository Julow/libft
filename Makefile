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
C_DIR = srcs/
O_DIR = o/

FLAGS = -Wall -Wextra -Werror -O2

C_FILES = $(shell ls -1 $(C_DIR) | grep ".c")

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rc $@ $^ && printf "\033[0;32m" || printf "\033[0;31m"
	@printf "%-24s\033[1;30m<<--\033[0;0m\n" "$@"
	@ranlib $@

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@printf "\033[0;0m%-24s\033[1;30m-->>	" "$<"
	@gcc $(FLAGS) -I$(H_DIR) -o $@ -c $< && printf "\033[0;32m$@" || (printf "\033[0;31m$@" && exit 1)
	@printf "\033[0;0m\n"

debug: _debug all clean

clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re: fclean all

_debug:
	$(eval FLAGS += -g)

.PHONY: all debug clean fclean re _debug
