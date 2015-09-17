# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 13:05:11 by jaguillo          #+#    #+#              #
#    Updated: 2015/09/17 16:51:33 by jaguillo         ###   ########.fr        #
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

EXTRAS := ft_term ft_draw
EXTRA_DIR := extra

SHELL := /bin/bash

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

JOBS ?= 4

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
COUNT = 0
TOTAL := $(words $(filter %.c,$(C_FILES)))

PRINT_BAR = printf "\r%100c\r\033[42;39m%-56s\033[0;32m %s\033[0m" " " "`printf "%$$(((($(COUNT)) * 51 - 1) / $(TOTAL)))s\033[100m"`"
PRINT_OK = $(eval COUNT += +1) $(PRINT_BAR) "$(subst $(C_DIR)/,,$<)"
PRINT_LINK = $(eval COUNT = $(TOTAL)) $(PRINT_BAR) "$@" && echo
PRINT_ERROR = (printf "%60c\r \033[0;31m%s\033[0m\n" " " "$<" && exit 1)

# Call $(NAME) in async mode
all:
	@make -j$(JOBS) $(NAME)

# Compile all sources and build the .a archive
$(NAME): $(O_FILES)
	@ar rcs $@ $^ && $(PRINT_LINK)

# Compile .s sources (only if nasm is installed and support ASM_FORMAT)
ifeq ($(ASM_ENABLE),1)
ifneq ($(shell nasm -v 2> /dev/null),)
ifneq ($(shell nasm -hf | grep "$(ASM_FORMAT)"),)
$(O_DIR)/%.o: %.s
	@nasm $(ASM_SPECIAL) $(ASM_FLAGS) -o $@ $< && $(PRINT_OK) || $(PRINT_ERROR)
endif
endif
endif

# Compile .c sources
$(O_DIR)/%.o: %.c
	@clang $(C_FLAGS) $(LINKS) -o $@ -c $< && $(PRINT_OK) || $(PRINT_ERROR)

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

.PHONY: all debug clean fclean re rebug _noasm _debug $(addprefix extra/,$(EXTRAS))
.SILENT:
