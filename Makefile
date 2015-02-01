# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 13:05:11 by jaguillo          #+#    #+#              #
#    Updated: 2015/02/01 00:19:08 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

H_DIR = .
C_DIR = srcs
O_DIR = o

C_FLAGS = -Wall -Wextra -Werror -O2
LINKS = -I$(H_DIR) $(FT_CONFIG)
DEBUG = 0

ifeq ($(shell uname),Linux)
	ASM_FLAGS = -f elf64 -DLINUX -Wall
else
	ASM_FLAGS = -f macho64 --prefix _ -Wall
endif

C_FILES = $(shell find $(C_DIR) -type f -print)
C_DIRS = $(shell find $(C_DIR) -type d -print)

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
TMP = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)
O_FILES = $(TMP:$(C_DIR)/%.s=$(O_DIR)/%.o)

all:
	@if [ "$(DEBUG)" -eq "1" ]; then \
		make -j4 _debug $(NAME); else \
		make -j4 $(NAME); fi

$(NAME): $(O_FILES)
	@ar rcs $@ $^ && printf "\033[0;32m" || printf "\033[0;31m"
	@printf "%-34s \033[1;30m<<--\033[0;0m\n" "$@"

ifneq ($(shell nasm -v 2> /dev/null),)
$(O_DIR)/%.o: $(C_DIR)/%.s
	@mkdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@nasm $(ASM_FLAGS) -o $@ $< \
	&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
	|| (printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;31m$@\033[0;0m\n" "$<" \
		&& exit 1)
endif

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc $(C_FLAGS) $(LINKS) -o $@ -c $< \
	&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
	|| (printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;31m$@\033[0;0m\n" "$<" \
		&& exit 1)

debug: _debug all

clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re: fclean all

rebug: fclean debug

update: fclean
	@cd .. ; git subtree pull --prefix=libft --squash \
		git@github.com:Julow/libft.git master -m "Update libft"

_debug:
	$(eval C_FLAGS = -Wall -Wextra -g -D DEBUG_MODE)
	$(eval ASM_FLAGS += -g)
	$(eval DEBUG = 1)

.PHONY: all debug clean fclean re rebug update _debug
