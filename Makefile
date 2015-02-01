# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 13:05:11 by jaguillo          #+#    #+#              #
#    Updated: 2015/02/01 00:58:10 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

H_DIR = .
C_DIR = srcs
O_DIR = o

# GCC flags
C_FLAGS = -Wall -Wextra -Werror -O2
LINKS = -I$(H_DIR) $(FT_CONFIG)

# NASM flags
ifeq ($(shell uname),Linux)
	ASM_FLAGS = -f elf64 -DLINUX -Wall
else
	ASM_FLAGS = -f macho64 --prefix _ -Wall
endif

# Debug mode
DEBUG = 0

# Search source files
C_FILES = $(shell find $(C_DIR) -type f -print)
C_DIRS = $(shell find $(C_DIR) -type d -print)

# Build .o list
O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
TMP = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)
O_FILES = $(TMP:$(C_DIR)/%.s=$(O_DIR)/%.o)

# Create O_DIR and childs
$(shell mkdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null)

# Print
MSG_0 = "%-34s\033[1;30m -->>  \033[0;32m%s\033[0;0m\n"
MSG_1 = "%-34s\033[1;30m -->>  \033[0;31m%s\033[0;0m\n"
MSG_2 = "%-34s\033[1;30m <<--\033[0;0m\n"

all:
	@if [ "$(DEBUG)" -eq "1" ]; then \
		make -j4 _debug $(NAME); else \
		make -j4 $(NAME); fi

# Compile all sources and build the .a archive
$(NAME): $(O_FILES)
	@ar rcs $@ $^ && printf "\033[0;32m" || printf "\033[0;31m"
	@printf $(MSG_2) "$@"

# Compile .s sources (only if nasm is installed)
ifneq ($(shell nasm -v 2> /dev/null),)
$(O_DIR)/%.o: $(C_DIR)/%.s
	@nasm $(ASM_FLAGS) -o $@ $< \
		&& printf $(MSG_0) "$<" "$@" || (printf $(MSG_1) "$<" "$@" && exit 1)
endif

# Compile .c sources
$(O_DIR)/%.o: $(C_DIR)/%.c
	@gcc $(C_FLAGS) $(LINKS) -o $@ -c $< \
		&& printf $(MSG_0) "$<" "$@" || (printf $(MSG_1) "$<" "$@" && exit 1)

# Enable debug mode, change flags and build
debug: _debug all

# Remove all .o files
clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null

# Remove all .o files and the .a archive
fclean: clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

# Remove all builded files and rebuild
re: fclean all

# Remove all builded files and rebuild in debug mode
rebug: fclean debug

# Update the libft (only with subtree)
update: fclean
	@cd .. ; git subtree pull --prefix=libft --squash \
		git@github.com:Julow/libft.git master -m "Update libft"

# Enable debug mode and change compilation flags
_debug:
	$(eval C_FLAGS = -Wall -Wextra -g -D DEBUG_MODE)
	$(eval ASM_FLAGS += -g)
	$(eval DEBUG = 1)

.PHONY: all debug clean fclean re rebug update _debug
