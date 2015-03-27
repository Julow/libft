# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/03/27 15:37:59 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -I ../..

all: ft_rmatch

ft_rmatch: libft
	clang $(FLAGS) reg_test.c -o $@ -L ../.. -lft

libft:
	@make -C ../..

clean:
	rm -f ft_rmatch

fclean: clean

re: fclean all

test: all
	@echo "	" True
	./ft_rmatch "" ""
	./ft_rmatch "abc" "abc"
	./ft_rmatch "abcdef" "a?wcdef"
	./ft_rmatch "abcdef" "a?2wdef"
	./ft_rmatch "abcdef" "a?1,2wdef"
	./ft_rmatch "abcdef" "a?1,3wdef"
	./ft_rmatch "abcdef" "a?+wdef"
	./ft_rmatch "abcdef" "a?+w"
	./ft_rmatch "a0cdef" "a?+dcdef"
	./ft_rmatch "127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d"
	./ft_rmatch "127.0.0.11" "?1,3d?3'.?1,3d'"
	./ft_rmatch "127.0.0.11:4242" "?1,3d.?1,3d.?1,3d.?1,3d:?+d"
	./ft_rmatch "ababab" "??'ab'??'ab'??'ab'"
	./ft_rmatch "ababab" "?*[ab]"
	./ft_rmatch "ababab" "?*[a-b]"
	./ft_rmatch "ababab" "?*'ab'"
	./ft_rmatch "abababababab" "??'ab'?*'ab'??'ab'"
	@echo "	" False
	./ft_rmatch "" "a"
	./ft_rmatch "a" ""
	./ft_rmatch "abcdef" 'a?+z'
	./ft_rmatch "abcdef" 'a?+zbcdef'
	./ft_rmatch "abcd" "abc"
	./ft_rmatch "abc" "abcd"
	./ft_rmatch "0127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d"
	./ft_rmatch "127.00.11" "?1,3d.?1,3d.?1,3d.?1,3d"
	./ft_rmatch "127.0.0.11.5" "?1,3d.?1,3d.?1,3d.?1,3d"
