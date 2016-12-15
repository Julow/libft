/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 00:01:49 by juloo             #+#    #+#             */
/*   Updated: 2016/12/15 12:57:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

/*
** ?omg
** import re
** out("\n")
** out("uint32_t			g_is_table[256] = {\n")
** for c in map(chr, range(128)):
** 	classes = [name for name, reg in FT_IS_CLASSES if re.match(reg, c)]
** 	out("\t[%s] = %s,\n" % (
** 		"'\\''" if c == "'"
** 		else "'%s'" % c.encode("unicode-escape").decode("ascii"),
** 		" | ".join(classes) if len(classes) > 0 else "0")
** 	)
** out("};\n")
** out("\n")
*/

uint32_t			g_is_table[256] = {
	['\x00'] = _IS_CNTRL,
	['\x01'] = _IS_CNTRL,
	['\x02'] = _IS_CNTRL,
	['\x03'] = _IS_CNTRL,
	['\x04'] = _IS_CNTRL,
	['\x05'] = _IS_CNTRL,
	['\x06'] = _IS_CNTRL,
	['\x07'] = _IS_CNTRL,
	['\x08'] = _IS_CNTRL,
	['\t'] = IS_TAB,
	['\n'] = IS_NEWLINE,
	['\x0b'] = _IS_WHITE,
	['\x0c'] = _IS_WHITE,
	['\r'] = _IS_WHITE,
	['\x0e'] = _IS_CNTRL,
	['\x0f'] = _IS_CNTRL,
	['\x10'] = _IS_CNTRL,
	['\x11'] = _IS_CNTRL,
	['\x12'] = _IS_CNTRL,
	['\x13'] = _IS_CNTRL,
	['\x14'] = _IS_CNTRL,
	['\x15'] = _IS_CNTRL,
	['\x16'] = _IS_CNTRL,
	['\x17'] = _IS_CNTRL,
	['\x18'] = _IS_CNTRL,
	['\x19'] = _IS_CNTRL,
	['\x1a'] = _IS_CNTRL,
	['\x1b'] = _IS_CNTRL,
	['\x1c'] = _IS_CNTRL,
	['\x1d'] = _IS_CNTRL,
	['\x1e'] = _IS_CNTRL,
	['\x1f'] = _IS_CNTRL,
	[' '] = IS_SPACE,
	['!'] = _IS_PUNCT,
	['"'] = _IS_PUNCT,
	['#'] = _IS_PUNCT,
	['$'] = _IS_PUNCT,
	['%'] = _IS_PUNCT,
	['&'] = _IS_PUNCT,
	['\''] = _IS_PUNCT,
	['('] = _IS_PUNCT,
	[')'] = _IS_PUNCT,
	['*'] = _IS_PUNCT,
	['+'] = _IS_PUNCT,
	[','] = _IS_PUNCT,
	['-'] = _IS_PUNCT,
	['.'] = _IS_PUNCT,
	['/'] = _IS_PUNCT,
	['0'] = IS_DIGIT,
	['1'] = IS_DIGIT,
	['2'] = IS_DIGIT,
	['3'] = IS_DIGIT,
	['4'] = IS_DIGIT,
	['5'] = IS_DIGIT,
	['6'] = IS_DIGIT,
	['7'] = IS_DIGIT,
	['8'] = IS_DIGIT,
	['9'] = IS_DIGIT,
	[':'] = _IS_PUNCT,
	[';'] = _IS_PUNCT,
	['<'] = _IS_PUNCT,
	['='] = _IS_PUNCT,
	['>'] = _IS_PUNCT,
	['?'] = _IS_PUNCT,
	['@'] = _IS_PUNCT,
	['A'] = IS_XUPPER,
	['B'] = IS_XUPPER,
	['C'] = IS_XUPPER,
	['D'] = IS_XUPPER,
	['E'] = IS_XUPPER,
	['F'] = IS_XUPPER,
	['G'] = _IS_UPPER,
	['H'] = _IS_UPPER,
	['I'] = _IS_UPPER,
	['J'] = _IS_UPPER,
	['K'] = _IS_UPPER,
	['L'] = _IS_UPPER,
	['M'] = _IS_UPPER,
	['N'] = _IS_UPPER,
	['O'] = _IS_UPPER,
	['P'] = _IS_UPPER,
	['Q'] = _IS_UPPER,
	['R'] = _IS_UPPER,
	['S'] = _IS_UPPER,
	['T'] = _IS_UPPER,
	['U'] = _IS_UPPER,
	['V'] = _IS_UPPER,
	['W'] = _IS_UPPER,
	['X'] = _IS_UPPER,
	['Y'] = _IS_UPPER,
	['Z'] = _IS_UPPER,
	['['] = _IS_PUNCT,
	['\\'] = _IS_PUNCT,
	[']'] = _IS_PUNCT,
	['^'] = _IS_PUNCT,
	['_'] = IS_UNDERSCORE,
	['`'] = _IS_PUNCT,
	['a'] = IS_XLOWER,
	['b'] = IS_XLOWER,
	['c'] = IS_XLOWER,
	['d'] = IS_XLOWER,
	['e'] = IS_XLOWER,
	['f'] = IS_XLOWER,
	['g'] = _IS_LOWER,
	['h'] = _IS_LOWER,
	['i'] = _IS_LOWER,
	['j'] = _IS_LOWER,
	['k'] = _IS_LOWER,
	['l'] = _IS_LOWER,
	['m'] = _IS_LOWER,
	['n'] = _IS_LOWER,
	['o'] = _IS_LOWER,
	['p'] = _IS_LOWER,
	['q'] = _IS_LOWER,
	['r'] = _IS_LOWER,
	['s'] = _IS_LOWER,
	['t'] = _IS_LOWER,
	['u'] = _IS_LOWER,
	['v'] = _IS_LOWER,
	['w'] = _IS_LOWER,
	['x'] = _IS_LOWER,
	['y'] = _IS_LOWER,
	['z'] = _IS_LOWER,
	['{'] = _IS_PUNCT,
	['|'] = _IS_PUNCT,
	['}'] = _IS_PUNCT,
	['~'] = _IS_PUNCT,
	['\x7f'] = _IS_CNTRL,
};

/*
** ?end
*/

bool			ft_is(char c, uint32_t mask)
{
	if (IS(c, mask))
		return (true);
	return (false);
}
