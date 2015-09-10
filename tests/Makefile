# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juloo <juloo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/10 22:34:26 by juloo             #+#    #+#              #
#    Updated: 2015/09/10 23:13:56 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTS := deque evalexpr hmap list vector rmatch rfind sort

FLAGS := -Wall -Wextra -O2 -g
HEADS := -I ..
LINKS := -L .. -lft

SHELL := /bin/bash

all:
	echo "Available tests: $(TESTS)"

$(TESTS): %: _%

_evalexpr: LINKS += -lm
_%: test_%.c libft
	clang $(FLAGS) $(HEADS) $< -o $@ $(LINKS)

libft:
	make -C ..

clean:
	rm -f $(addprefix _,$(TESTS))

fclean: clean

.PHONY: all clean fclean $(TESTS) libft
.SILENT:

# Tests

deque hmap list vector:
	./_$@

evalexpr:
	./_evalexpr "5" 5
	./_evalexpr "(5)" 5
	./_evalexpr "(((5)))" 5
	./_evalexpr "1 + 3" 4
	./_evalexpr "1 + 3 * 2" 7
	./_evalexpr "(1 + 3) * 2" 8
	./_evalexpr "3^2" 9
	./_evalexpr "2 * 9 * 4" 72
	./_evalexpr "2 * 3^2 * 4 + 1" 73
	./_evalexpr "(2 * 3)^2 * 4" 144
	./_evalexpr "36 * 4" 144
	./_evalexpr "36 % 5" 1
	./_evalexpr "sqrt 5^2" 5
	./_evalexpr "sqrt 5.8^2" 5.8
	./_evalexpr "(sqrt 5.8)^2" 5.8
	./_evalexpr "abs -5" 5
	./_evalexpr "abs (-5)" 5
	./_evalexpr "abs(-5)" 5
	./_evalexpr "abs-5" 5
	./_evalexpr "abs-5.3" 5.3
	./_evalexpr "-5.3" -5.3
	./_evalexpr "-5 + 0.3" -4.7
	./_evalexpr "2 / 0"
	./_evalexpr "0-(2 / 0)"
	./_evalexpr "cos 0" 1

rmatch:
	./_rmatch "" "" 1
	./_rmatch "abc" "abc" 1
	./_rmatch "abcdef" "a?wcdef" 1
	./_rmatch "abcdef" "a?2wdef" 1
	./_rmatch "abcdef" "a?1,2wdef" 1
	./_rmatch "abcdef" "a?1,3wdef" 1
	./_rmatch "abcdef" "a?+wdef" 1
	./_rmatch "abcdef" "a?+w" 1
	./_rmatch "a0cdef" "a?+dcdef" 1
	./_rmatch "127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 1
	./_rmatch "127.0.0.11" "?1,3d?3(.?1,3d)" 1
	./_rmatch "127.0.0.11:4242" "?1,3d.?1,3d.?1,3d.?1,3d:?+d" 1
	./_rmatch "ababab" "??'ab'??'ab'??'ab'" 1
	./_rmatch "ababab" "?*[ab]" 1
	./_rmatch "ababab" "?*[a-b]" 1
	./_rmatch "ababab" "?*'ab'" 1
	./_rmatch "abababababab" "??'ab'?*'ab'??'ab'" 1
	./_rmatch "aaaaabaaaa" "?*'a'?[abc]?4[a]" 1
	./_rmatch "abcdef" "?w|dbcdef" 1
	./_rmatch "0bcdef" "?w|dbcdef" 1
	./_rmatch "abcdef" "ab?![A-Zabd-z]def" 1
	./_rmatch "abcd" "ab?[ab]|[cd]d" 1
	./_rmatch "abcd" "ab?[abc]|[d]d" 1
	./_rmatch "a" "?:a|:b|:c|:d|:e|:f|:g|:h" 1
	./_rmatch "h" "?:a|:b|:c|:d|:e|:f|:g|:h" 1
	./_rmatch "c" "?[abcdefgh]" 1
	./_rmatch "c" "?[a-h]" 1
	./_rmatch "abcd" "?!'xd'cd" 1
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?*:a" 1
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?*'a'" 1
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'" 1
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'a" 1
	./_rmatch "aaaaaaaaabaaaaaaaaa" "?*:a?.?+:a" 1
	./_rmatch "aaaaaaaaabaaaaaaaaa" "?*:a?+.?+:a" 1
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:?" 1
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
	./_rmatch "Lol Lol Lol" "?+w?+s?+w?+s?+w" 1
	./_rmatch " Lol Lol Lol" "?*s?+w?+s?+w?+s?+w" 1
	./_rmatch "Lol Lol Lol" "?*s?+w?+s?+w?+s?+w" 1
	./_rmatch "Lol Lol Lol" "?+w?+s?+w?+s?+w?*s" 1
	./_rmatch "Lol Lol Lol " "?+w?+s?+w?+s?+w?*s" 1
	./_rmatch "Lol Lol Lol" "?*s?+w?+s?+w?+s?+w?*s" 1
	./_rmatch "Lol Lol Lol " "?*s?+w?+s?+w?+s?+w?*s" 1
	./_rmatch " Lol Lol Lol" "?*s?+w?+s?+w?+s?+w?*s" 1
	./_rmatch " Lol Lol Lol " "?*s?+w?+s?+w?+s?+w?*s" 1
	./_rmatch "abc" "?(?*:a?*:b?*:c)" 1
	./_rmatch "aabbcc" "?*(?*:a?*:b?*:c)" 1
	./_rmatch "aabbccabcaaaabccccabbbcc" "?*(?*:a?*:b?*:c)" 1
	./_rmatch "0" "?&i" 1
	./_rmatch "2147483647" "?&i" 1
	./_rmatch "-2147483648" "?&i" 1
	./_rmatch "AaAaAaAa" "?i*:a" 1
	./_rmatch "AaAaAaAa" "?i*'a'" 1
	./_rmatch "AaAaAaAa" "?i*'aa'" 1
	./_rmatch "lol'lol'lol" "?+w?('?'lol'')?+w" 1
	./_rmatch "lol'lol'lol" "?+w?('?(lol?:'))?+w" 1
	./_rmatch "aaaa" "?*(?:a)" 1
	./_rmatch "abc123Abc0ABC_LOL" "?*[a-zA-Z0-9_]" 1
	./_rmatch "abcdef" "?!*d" 1
	./_rmatch "l0l1l2" "?*(l?d)" 1
	./_rmatch "" "a" 0
	./_rmatch "a" "" 0
	./_rmatch "abcdef" 'a?+z' 0
	./_rmatch "abcdef" 'a?+zbcdef' 0
	./_rmatch "abcd" "abc" 0
	./_rmatch "abc" "abcd" 0
	./_rmatch "abcd" "?!'ab'abcd" 0
	./_rmatch "abcd" "?!'ab'cd" 0
	./_rmatch "abc" "ab?[ab]|[cd]d" 0
	./_rmatch "abcd" "ab?[abc]|[cd]" 0
	./_rmatch "abcdef" "ab?![c]def" 0
	./_rmatch "abcd" "?!'cd'abcd" 0
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'?:a'" 0
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?*''" 0
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?+[]" 0
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?*:b" 0
	./_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'b" 0
	./_rmatch "2147483648" "?&i" 0
	./_rmatch "-" "?&i" 0
	./_rmatch "AaAaAaAa" "?i*:A" 0
	./_rmatch "0127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	./_rmatch "127.00.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	./_rmatch "127.0.0.11.5" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	./_rmatch "abc0def" "?!*d" 0

sort:
	@echo " -----> Sorted <-----"
	./_sort a
	./_sort a b
	./_sort a b c
	./_sort a b c d
	./_sort a b c d e f g h i j
	./_sort a b c d e f g h i j k l m n o p q r s t u v w x y z
	./_sort `ls /bin`
	@echo " -----> Reversed <-----"
	./_sort d c
	./_sort d c b
	./_sort d c b a
	./_sort j i h g f e d c b a
	./_sort z y x w v u t s r q p o n m l k j i h g f e d c b a
	./_sort `ls -r /bin`
	@echo " -----> Fix random <-----"
	./_sort g u o j
	./_sort m n v i r
	./_sort d g m c r a k
	./_sort w b n p h q t l i z e o c x
	./_sort n d l c m e g j o y w t k i b p a u h q r z f x s v
	./_sort t p u e d m k a j v h z b x f r y s c l o g i w q n
	./_sort x t j d k u e g y l a r c n f z h i q o s p b m w v
	@echo " -----> Random <-----"
	./_sort `seq 1 3 | shuf`
	./_sort `seq 1 5 | shuf`
	./_sort `seq 1 10 | shuf`
	./_sort `seq 1 20 | shuf`
	./_sort `seq 1 100 | shuf`
	./_sort `ls -r /bin | shuf`
	@echo " -----> Dupplicate <-----"
	./_sort `seq 0 2`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}
	./_sort `seq 0 10`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}
	./_sort `seq 0 15`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}
	./_sort `echo \`seq 0 15\`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,} | shuf`
	./_sort `echo \`seq 0 10\`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,} | shuf`
