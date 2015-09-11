# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juloo <juloo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/10 22:34:26 by juloo             #+#    #+#              #
#    Updated: 2015/09/12 00:35:00 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTS := deque evalexpr hmap list vector rmatch rfind sort var path

FLAGS := -Wall -Wextra -O2 -g
HEADS := -I ..
LINKS := -L .. -lft

SHELL := /bin/bash

all:
	echo "Available tests: $(TESTS)"

$(TESTS): %: libft out_%
%: libft out_%
	./out_$@

out_%: test_%.c
	clang $(FLAGS) $(HEADS) $< -o $@ $(LINKS)

libft:
	make -C ..

clean:
	rm -f $(addprefix out_,$(TESTS))

fclean: clean

.PHONY: all clean fclean libft
.SILENT:

# Extra flags

evalexpr: LINKS += -lm

# Tests

path:
	./out_path "" ""
	./out_path "" "libft.h"
	./out_path "include" "libft.h"
	./out_path "libft/include" "libft.h"
	./out_path "libft/include" ""
	./out_path "libft/include" "/"
	./out_path "/" "libft.h"
	./out_path "/home/juloo" "libft.h"
	./out_path "" "/"

evalexpr:
	./out_evalexpr "5" 5
	./out_evalexpr "(5)" 5
	./out_evalexpr "(((5)))" 5
	./out_evalexpr "1 + 3" 4
	./out_evalexpr "1 + 3 * 2" 7
	./out_evalexpr "(1 + 3) * 2" 8
	./out_evalexpr "3^2" 9
	./out_evalexpr "2 * 9 * 4" 72
	./out_evalexpr "2 * 3^2 * 4 + 1" 73
	./out_evalexpr "(2 * 3)^2 * 4" 144
	./out_evalexpr "36 * 4" 144
	./out_evalexpr "36 % 5" 1
	./out_evalexpr "sqrt 5^2" 5
	./out_evalexpr "sqrt 5.8^2" 5.8
	./out_evalexpr "(sqrt 5.8)^2" 5.8
	./out_evalexpr "abs -5" 5
	./out_evalexpr "abs (-5)" 5
	./out_evalexpr "abs(-5)" 5
	./out_evalexpr "abs-5" 5
	./out_evalexpr "abs-5.3" 5.3
	./out_evalexpr "-5.3" -5.3
	./out_evalexpr "-5 + 0.3" -4.7
	./out_evalexpr "2 / 0"
	./out_evalexpr "0-(2 / 0)"
	./out_evalexpr "cos 0" 1

rmatch:
	./out_rmatch "" "" 1
	./out_rmatch "abc" "abc" 1
	./out_rmatch "abcdef" "a?wcdef" 1
	./out_rmatch "abcdef" "a?2wdef" 1
	./out_rmatch "abcdef" "a?1,2wdef" 1
	./out_rmatch "abcdef" "a?1,3wdef" 1
	./out_rmatch "abcdef" "a?+wdef" 1
	./out_rmatch "abcdef" "a?+w" 1
	./out_rmatch "a0cdef" "a?+dcdef" 1
	./out_rmatch "127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 1
	./out_rmatch "127.0.0.11" "?1,3d?3(.?1,3d)" 1
	./out_rmatch "127.0.0.11:4242" "?1,3d.?1,3d.?1,3d.?1,3d:?+d" 1
	./out_rmatch "ababab" "??'ab'??'ab'??'ab'" 1
	./out_rmatch "ababab" "?*[ab]" 1
	./out_rmatch "ababab" "?*[a-b]" 1
	./out_rmatch "ababab" "?*'ab'" 1
	./out_rmatch "abababababab" "??'ab'?*'ab'??'ab'" 1
	./out_rmatch "aaaaabaaaa" "?*'a'?[abc]?4[a]" 1
	./out_rmatch "abcdef" "?w|dbcdef" 1
	./out_rmatch "0bcdef" "?w|dbcdef" 1
	./out_rmatch "abcdef" "ab?![A-Zabd-z]def" 1
	./out_rmatch "abcd" "ab?[ab]|[cd]d" 1
	./out_rmatch "abcd" "ab?[abc]|[d]d" 1
	./out_rmatch "a" "?:a|:b|:c|:d|:e|:f|:g|:h" 1
	./out_rmatch "h" "?:a|:b|:c|:d|:e|:f|:g|:h" 1
	./out_rmatch "c" "?[abcdefgh]" 1
	./out_rmatch "c" "?[a-h]" 1
	./out_rmatch "abcd" "?!'xd'cd" 1
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?*:a" 1
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?*'a'" 1
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'" 1
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'a" 1
	./out_rmatch "aaaaaaaaabaaaaaaaaa" "?*:a?.?+:a" 1
	./out_rmatch "aaaaaaaaabaaaaaaaaa" "?*:a?+.?+:a" 1
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:?" 1
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
	./out_rmatch "Lol Lol Lol" "?+w?+s?+w?+s?+w" 1
	./out_rmatch " Lol Lol Lol" "?*s?+w?+s?+w?+s?+w" 1
	./out_rmatch "Lol Lol Lol" "?*s?+w?+s?+w?+s?+w" 1
	./out_rmatch "Lol Lol Lol" "?+w?+s?+w?+s?+w?*s" 1
	./out_rmatch "Lol Lol Lol " "?+w?+s?+w?+s?+w?*s" 1
	./out_rmatch "Lol Lol Lol" "?*s?+w?+s?+w?+s?+w?*s" 1
	./out_rmatch "Lol Lol Lol " "?*s?+w?+s?+w?+s?+w?*s" 1
	./out_rmatch " Lol Lol Lol" "?*s?+w?+s?+w?+s?+w?*s" 1
	./out_rmatch " Lol Lol Lol " "?*s?+w?+s?+w?+s?+w?*s" 1
	./out_rmatch "abc" "?(?*:a?*:b?*:c)" 1
	./out_rmatch "aabbcc" "?*(?*:a?*:b?*:c)" 1
	./out_rmatch "aabbccabcaaaabccccabbbcc" "?*(?*:a?*:b?*:c)" 1
	./out_rmatch "0" "?&i" 1
	./out_rmatch "2147483647" "?&i" 1
	./out_rmatch "-2147483648" "?&i" 1
	./out_rmatch "AaAaAaAa" "?i*:a" 1
	./out_rmatch "AaAaAaAa" "?i*'a'" 1
	./out_rmatch "AaAaAaAa" "?i*'aa'" 1
	./out_rmatch "lol'lol'lol" "?+w?('?'lol'')?+w" 1
	./out_rmatch "lol'lol'lol" "?+w?('?(lol?:'))?+w" 1
	./out_rmatch "aaaa" "?*(?:a)" 1
	./out_rmatch "abc123Abc0ABC_LOL" "?*[a-zA-Z0-9_]" 1
	./out_rmatch "abcdef" "?!*d" 1
	./out_rmatch "l0l1l2" "?*(l?d)" 1
	./out_rmatch "" "a" 0
	./out_rmatch "a" "" 0
	./out_rmatch "abcdef" 'a?+z' 0
	./out_rmatch "abcdef" 'a?+zbcdef' 0
	./out_rmatch "abcd" "abc" 0
	./out_rmatch "abc" "abcd" 0
	./out_rmatch "abcd" "?!'ab'abcd" 0
	./out_rmatch "abcd" "?!'ab'cd" 0
	./out_rmatch "abc" "ab?[ab]|[cd]d" 0
	./out_rmatch "abcd" "ab?[abc]|[cd]" 0
	./out_rmatch "abcdef" "ab?![c]def" 0
	./out_rmatch "abcd" "?!'cd'abcd" 0
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'?:a'" 0
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?*''" 0
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?+[]" 0
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?*:b" 0
	./out_rmatch "aaaaaaaaaaaaaaaaaaa" "?!*'b'b" 0
	./out_rmatch "2147483648" "?&i" 0
	./out_rmatch "-" "?&i" 0
	./out_rmatch "AaAaAaAa" "?i*:A" 0
	./out_rmatch "0127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	./out_rmatch "127.00.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	./out_rmatch "127.0.0.11.5" "?1,3d.?1,3d.?1,3d.?1,3d" 0
	./out_rmatch "abc0def" "?!*d" 0

sort:
	@echo " -----> Sorted <-----"
	./out_sort a
	./out_sort a b
	./out_sort a b c
	./out_sort a b c d
	./out_sort a b c d e f g h i j
	./out_sort a b c d e f g h i j k l m n o p q r s t u v w x y z
	./out_sort `ls /bin`
	@echo " -----> Reversed <-----"
	./out_sort d c
	./out_sort d c b
	./out_sort d c b a
	./out_sort j i h g f e d c b a
	./out_sort z y x w v u t s r q p o n m l k j i h g f e d c b a
	./out_sort `ls -r /bin`
	@echo " -----> Fix random <-----"
	./out_sort g u o j
	./out_sort m n v i r
	./out_sort d g m c r a k
	./out_sort w b n p h q t l i z e o c x
	./out_sort n d l c m e g j o y w t k i b p a u h q r z f x s v
	./out_sort t p u e d m k a j v h z b x f r y s c l o g i w q n
	./out_sort x t j d k u e g y l a r c n f z h i q o s p b m w v
	@echo " -----> Random <-----"
	./out_sort `seq 1 3 | shuf`
	./out_sort `seq 1 5 | shuf`
	./out_sort `seq 1 10 | shuf`
	./out_sort `seq 1 20 | shuf`
	./out_sort `seq 1 100 | shuf`
	./out_sort `ls -r /bin | shuf`
	@echo " -----> Dupplicate <-----"
	./out_sort `seq 0 2`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}
	./out_sort `seq 0 10`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}
	./out_sort `seq 0 15`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,}
	./out_sort `echo \`seq 0 15\`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,} | shuf`
	./out_sort `echo \`seq 0 10\`{,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,} | shuf`
