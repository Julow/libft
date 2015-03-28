#!/bin/bash

function test()
{
	MATCH="`./ft_rmatch "$1" "$2"`"
	if [[ ! "$MATCH" -eq "$3" ]]; then
		MATCH="$MATCH"" (FAIL)"
	fi
	printf "%-22s %-25s %s\n" "$1" "$2" "$MATCH"
};

test "" "" 1
test "abc" "abc" 1
test "abcdef" "a?wcdef" 1
test "abcdef" "a?2wdef" 1
test "abcdef" "a?1,2wdef" 1
test "abcdef" "a?1,3wdef" 1
test "abcdef" "a?+wdef" 1
test "abcdef" "a?+w" 1
test "a0cdef" "a?+dcdef" 1
test "127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 1
test "127.0.0.11" "?1,3d?3'.?1,3d'" 1
test "127.0.0.11:4242" "?1,3d.?1,3d.?1,3d.?1,3d:?+d" 1
test "ababab" "??'ab'??'ab'??'ab'" 1
test "ababab" "?*[ab]" 1
test "ababab" "?*[a-b]" 1
test "ababab" "?*'ab'" 1
test "abababababab" "??'ab'?*'ab'??'ab'" 1
test "aaaaabaaaa" "?*'a'?[abc]?4[a]" 1
test "abcdef" "?w|dbcdef" 1
test "0bcdef" "?w|dbcdef" 1
test "abcdef" "ab?![A-Zabd-z]def" 1
test "abcd" "ab?[ab]|[cd]d" 1
test "abcd" "ab?[abc]|[d]d" 1
test "abcd" "?!'xd'cd" 1
test "aaaaaaaaaaaaaaaaaaa" "?*''" 1
test "aaaaaaaaaaaaaaaaaaa" "?*:a" 1
test "aaaaaaaaaaaaaaaaaaa" "?*'a'" 1
test "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
test "aaaaaaaaaaaaaaaaaaa" "?!*'b'" 1
test "aaaaaaaaabaaaaaaaaa" "?*:a?.?+:a" 1
test "aaaaaaaaabaaaaaaaaa" "?*:a?+.?+:a" 1
test "aaaaaaaaaaaaaaaaaaa" "?!*:?" 1
test "aaaaaaaaaaaaaaaaaaa" "?!*:b" 1
test "abc123Abc0ABC_LOL" "?*[a-zA-Z0-9_]" 1
test "abcdef" "?!*d" 1

test "" "a" 0
test "a" "" 0
test "abcdef" 'a?+z' 0
test "abcdef" 'a?+zbcdef' 0
test "abcd" "abc" 0
test "abc" "abcd" 0
test "abcd" "?!'ab'abcd" 0
test "abcd" "?!'ab'cd" 0
test "abc" "ab?[ab]|[cd]d" 0
test "abcd" "ab?[abc]|[cd]" 0
test "abcdef" "ab?![c]def" 0
test "abcd" "?!'cd'abcd" 0
test "aaaaaaaaaaaaaaaaaaa" "?+[]" 0
test "aaaaaaaaaaaaaaaaaaa" "?*:b" 0
test "0127.0.0.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
test "127.00.11" "?1,3d.?1,3d.?1,3d.?1,3d" 0
test "127.0.0.11.5" "?1,3d.?1,3d.?1,3d.?1,3d" 0
test "abc0def" "?!*d" 0
