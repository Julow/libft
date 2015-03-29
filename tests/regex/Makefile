# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/03/29 03:48:22 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -I ../..

all: ft_rmatch

ft_rmatch: libft
	clang $(FLAGS) reg_test.c -o $@ -L ../.. -lft

libft:
	@make -C ../.. debug

clean:
	rm -f ft_rmatch

fclean: clean

re: fclean all

test: all
	@./ft_rmatch "" "" 1
	@./ft_rmatch "abc" "abc" 1
	@./ft_rmatch "abcdef" "a?wcdef" 1
	@./ft_rmatch "abcdef" "a?2wdef" 1
	@./ft_rmatch "abcdef" "a?1,2wdef" 1
	@./ft_rmatch "abcdef" "a?1,3wdef" 1
	@./ft_rmatch "abcdef" "a?+wdef" 1
	@./ft_rmatch "abcdef" "a?+w" 1
	@./ft_rmatch "a0cdef" "a?+dcdef" 1
	@./ft_rmatch "127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 1
	@./ft_rmatch "127.0.0.11" "?1,3d?3'.?1,3d'" 1
	@./ft_rmatch "127.0.0.11:4242" "?1,3d.?1,3d.?1,3d.?1,3d:?+d" 1
	@./ft_rmatch "ababab" "??'ab'??'ab'??'ab'" 1
	@./ft_rmatch "ababab" "?*[ab]" 1
	@./ft_rmatch "ababab" "?*[a-b]" 1
	@./ft_rmatch "ababab" "?*'ab'" 1
	@./ft_rmatch "abababababab" "??'ab'?*'ab'??'ab'" 1
	@./ft_rmatch "aaaaabaaaa" "?*'a'?[abc]?4[a]" 1
	@./ft_rmatch "abcdef" "?w|dbcdef" 1
	@./ft_rmatch "0bcdef" "?w|dbcdef" 1
	@./ft_rmatch "abcdef" "ab?![A-Zabd-z]def" 1
	@./ft_rmatch "abcd" "ab?[ab]|[cd]d" 1
	@./ft_rmatch "abcd" "ab?[abc]|[d]d" 1
	@./ft_rmatch "abcd" "?!'xd'cd" 1
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?*:a" 1
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?*'a'" 1
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'" 1
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'a" 1
	@./ft_rmatch "aaaaaaaaabaaaaaaaaa" "?*:a?.?+:a" 1
	@./ft_rmatch "aaaaaaaaabaaaaaaaaa" "?*:a?+.?+:a" 1
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:?" 1
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
	@./ft_rmatch "aaaa" "?*'?:a'" 1
	@./ft_rmatch "abc123Abc0ABC_LOL" "?*[a-zA-Z0-9_]" 1
	@./ft_rmatch "abcdef" "?!*d" 1
	@./ft_rmatch "l0l1l2" "?*'l?d'" 1
	@./ft_rmatch "" "a" 0
	@./ft_rmatch "a" "" 0
	@./ft_rmatch "abcdef" 'a?+z' 0
	@./ft_rmatch "abcdef" 'a?+zbcdef' 0
	@./ft_rmatch "abcd" "abc" 0
	@./ft_rmatch "abc" "abcd" 0
	@./ft_rmatch "abcd" "?!'ab'abcd" 0
	@./ft_rmatch "abcd" "?!'ab'cd" 0
	@./ft_rmatch "abc" "ab?[ab]|[cd]d" 0
	@./ft_rmatch "abcd" "ab?[abc]|[cd]" 0
	@./ft_rmatch "abcdef" "ab?![c]def" 0
	@./ft_rmatch "abcd" "?!'cd'abcd" 0
	@./ft_rmatch "abcd" "?!*''abcd" 0
	@./ft_rmatch "abcd" "?*''abcd" 0
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'?:a'" 0
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?*''" 0
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?+[]" 0
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?*:b" 0
	@./ft_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'b" 0
	@./ft_rmatch "0127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	@./ft_rmatch "127.00.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	@./ft_rmatch "127.0.0.11.5" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	@./ft_rmatch "abc0def" "?!*d" 0
