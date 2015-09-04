# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 13:05:11 by jaguillo          #+#    #+#              #
#    Updated: 2015/09/04 17:32:04 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# exportable vars:
#  DEBUG_MODE	(0)		Enable debug flags
#  ASM_ENABLE	(1)		Enable/Disable ASM
#  FT_CONFIG	("")	Extra macros/includes (C only)
#

NAME := libft.a

H_DIR := .
C_DIR := srcs
O_DIR := o

EXTRAS := ft_term
EXTRA_DIR := extra

# Debug mode
ifeq ($(DEBUG_MODE),)
	export DEBUG_MODE := 0
endif

# GCC flags
C_DEBUG_FLAGS := -Wall -Wextra -g -D DEBUG_MODE

LINKS := -I$(H_DIR) -I$(EXTRA_DIR) $(FT_CONFIG)

ifeq ($(C_FLAGS),)
ifeq ($(DEBUG_MODE),1)
	C_FLAGS := $(C_DEBUG_FLAGS)
else
	C_FLAGS := -Wall -Wextra -Werror -O2
endif
endif

# NASM flags
ifeq ($(ASM_ENABLE),)
	export ASM_ENABLE = 1
endif

ASM_DEBUG_FLAGS := -Wall -g -D DEBUG_MODE

ifeq ($(ASM_FLAGS),)
ifeq ($(DEBUG_MODE),1)
	ASM_FLAGS := $(ASM_DEBUG_FLAGS)
else
	ASM_FLAGS := -Wall -Werror
endif
endif

ifeq ($(shell uname),Darwin)
	ASM_FORMAT := macho64
	ASM_SPECIAL := -f $(ASM_FORMAT) --prefix _
else
	ASM_FORMAT := elf64
	ASM_SPECIAL := -f $(ASM_FORMAT) -D LINUX
endif

# Search source files
C_FILES := $(shell find $(C_DIR) -type f -print) $(EXTRA_FILES)
C_DIRS := $(shell find $(C_DIR) $(EXTRA_DIR) -depth -type d -print)

# Build .o list
O_DIRS := $(addprefix $(O_DIR)/,$(C_DIRS))
O_FILES_TMP := $(C_FILES:%.c=$(O_DIR)/%.o)
O_FILES := $(O_FILES_TMP:%.s=$(O_DIR)/%.o)

# Create O_DIR and childs
$(shell mkdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || true)

# Print
MSG_0 := "%40c\r\033[0;32m%s\033[0;0m\r" " "
MSG_1 := "\033[0;31m%s\033[0;0m\n"
MSG_2 := "\r%40c\r%s\033[0;0m\n" " "

# Call $(NAME) in async mode
all:
	@make -j4 $(NAME)

# Compile all sources and build the .a archive
$(NAME): $(O_FILES)
	@ar rcs $@ $^ && printf "\033[0;32m" || printf "\033[0;31m"
	@printf $(MSG_2) "$@"

# Compile .s sources (only if nasm is installed and support ASM_FORMAT)
ifeq ($(ASM_ENABLE),1)
ifneq ($(shell nasm -v 2> /dev/null),)
ifneq ($(shell nasm -hf | grep "$(ASM_FORMAT)"),)
$(O_DIR)/%.o: %.s
	@nasm $(ASM_SPECIAL) $(ASM_FLAGS) -o $@ $< \
		&& printf $(MSG_0) "$<" || (printf $(MSG_1) "$<" && exit 1)
endif
endif
endif

# Compile .c sources
$(O_DIR)/%.o: %.c
	@clang $(C_FLAGS) $(LINKS) -o $@ -c $< \
		&& printf $(MSG_0) "$<" || (printf $(MSG_1) "$<" && exit 1)

# Enable debug mode, change flags and build
debug: _debug all

# Remove all .o files
clean:
	@rm $(O_FILES) 2> /dev/null || true
	@rmdir $(O_DIRS) $(O_DIR) 2> /dev/null || true

# Remove all .o files and the .a archive
fclean: clean
	@rm $(NAME) 2> /dev/null || true

# Remove all builded files and rebuild
re: fclean all

# Remove all builded files and rebuild in debug mode
rebug: fclean debug

# Extra
$(addprefix extra/,$(EXTRAS)):
	@EXTRA_FILES=`find $@ -type f | tr '\n' ' '` make

# Disable ASM
_noasm:
	$(eval ASM_ENABLE := 0)

# Enable debug mode and change compilation flags
_debug:
	$(eval C_FLAGS := $(C_DEBUG_FLAGS))
	$(eval ASM_FLAGS := $(ASM_DEBUG_FLAGS))
	$(eval DEBUG_MODE := 1)

.PHONY: all debug clean fclean re rebug update _noasm _debug $(addprefix extra/,$(EXTRAS))
