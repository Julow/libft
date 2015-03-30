# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/27 15:18:58 by jaguillo          #+#    #+#              #
#    Updated: 2015/03/30 12:12:24 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -I ../..

all:
	@make -C ../..
	clang $(FLAGS) test_rmatch.c -o test_rmatch -L ../.. -lft
	clang $(FLAGS) test_rfind.c -o test_rfind -L ../.. -lft

clean:
	@rm -f test_rmatch
	@rm -f test_rfind

fclean: clean

re: fclean all

test: all rmatch

rmatch:
	@./test_rmatch "" "" 1
	@./test_rmatch "abc" "abc" 1
	@./test_rmatch "abcdef" "a?wcdef" 1
	@./test_rmatch "abcdef" "a?2wdef" 1
	@./test_rmatch "abcdef" "a?1,2wdef" 1
	@./test_rmatch "abcdef" "a?1,3wdef" 1
	@./test_rmatch "abcdef" "a?+wdef" 1
	@./test_rmatch "abcdef" "a?+w" 1
	@./test_rmatch "a0cdef" "a?+dcdef" 1
	@./test_rmatch "127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 1
	@./test_rmatch "127.0.0.11" "?1,3d?3(.?1,3d)" 1
	@./test_rmatch "127.0.0.11:4242" "?1,3d.?1,3d.?1,3d.?1,3d:?+d" 1
	@./test_rmatch "ababab" "??'ab'??'ab'??'ab'" 1
	@./test_rmatch "ababab" "?*[ab]" 1
	@./test_rmatch "ababab" "?*[a-b]" 1
	@./test_rmatch "ababab" "?*'ab'" 1
	@./test_rmatch "abababababab" "??'ab'?*'ab'??'ab'" 1
	@./test_rmatch "aaaaabaaaa" "?*'a'?[abc]?4[a]" 1
	@./test_rmatch "abcdef" "?w|dbcdef" 1
	@./test_rmatch "0bcdef" "?w|dbcdef" 1
	@./test_rmatch "abcdef" "ab?![A-Zabd-z]def" 1
	@./test_rmatch "abcd" "ab?[ab]|[cd]d" 1
	@./test_rmatch "abcd" "ab?[abc]|[d]d" 1
	@./test_rmatch "a" "?:a|:b|:c|:d|:e|:f|:g|:h" 1
	@./test_rmatch "h" "?:a|:b|:c|:d|:e|:f|:g|:h" 1
	@./test_rmatch "c" "?[abcdefgh]" 1
	@./test_rmatch "c" "?[a-h]" 1
	@./test_rmatch "abcd" "?!'xd'cd" 1
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?*:a" 1
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?*'a'" 1
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'" 1
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'a" 1
	@./test_rmatch "aaaaaaaaabaaaaaaaaa" "?*:a?.?+:a" 1
	@./test_rmatch "aaaaaaaaabaaaaaaaaa" "?*:a?+.?+:a" 1
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:?" 1
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
	@./test_rmatch "abc" "?(?*:a?*:b?*:c)" 1
	@./test_rmatch "aabbcc" "?*(?*:a?*:b?*:c)" 1
	@./test_rmatch "aabbccabcaaaabccccabbbcc" "?*(?*:a?*:b?*:c)" 1
	@./test_rmatch "0" "?&i" 1
	@./test_rmatch "2147483647" "?&i" 1
	@./test_rmatch "-2147483648" "?&i" 1
	@./test_rmatch "AaAaAaAa" "?i*:a" 1
	@./test_rmatch "AaAaAaAa" "?i*'a'" 1
	@./test_rmatch "AaAaAaAa" "?i*'aa'" 1
	@./test_rmatch "lol'lol'lol" "?+w?('?'lol'')?+w" 1
	@./test_rmatch "lol'lol'lol" "?+w?('?(lol?:'))?+w" 1
	@./test_rmatch "aaaa" "?*(?:a)" 1
	@./test_rmatch "abc123Abc0ABC_LOL" "?*[a-zA-Z0-9_]" 1
	@./test_rmatch "abcdef" "?!*d" 1
	@./test_rmatch "l0l1l2" "?*(l?d)" 1
	@./test_rmatch "" "a" 0
	@./test_rmatch "a" "" 0
	@./test_rmatch "abcdef" 'a?+z' 0
	@./test_rmatch "abcdef" 'a?+zbcdef' 0
	@./test_rmatch "abcd" "abc" 0
	@./test_rmatch "abc" "abcd" 0
	@./test_rmatch "abcd" "?!'ab'abcd" 0
	@./test_rmatch "abcd" "?!'ab'cd" 0
	@./test_rmatch "abc" "ab?[ab]|[cd]d" 0
	@./test_rmatch "abcd" "ab?[abc]|[cd]" 0
	@./test_rmatch "abcdef" "ab?![c]def" 0
	@./test_rmatch "abcd" "?!'cd'abcd" 0
	@./test_rmatch "abcd" "?!*''abcd" 0
	@./test_rmatch "abcd" "?*''abcd" 0
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'?:a'" 0
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?*''" 0
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?+[]" 0
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?*:b" 0
	@./test_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'b" 0
	@./test_rmatch "2147483648" "?&i" 0
	@./test_rmatch "-" "?&i" 0
	@./test_rmatch "AaAaAaAa" "?i*:A" 0
	@./test_rmatch "0127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	@./test_rmatch "127.00.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	@./test_rmatch "127.0.0.11.5" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	@./test_rmatch "abc0def" "?!*d" 0

.PHONY: all clean fclean re test rmatch
