/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:56:34 by juloo             #+#    #+#             */
/*   Updated: 2016/02/10 17:37:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_H
# define REGEX_H

# include "ft/libft.h"

typedef struct s_regex			t_regex;
typedef struct s_regex_err		t_regex_err;
typedef struct s_reg			t_reg;
typedef struct s_rmatch			t_rmatch;

/*
** ========================================================================== **
** Regex
** -
** '?' <name>? <flags>? <n>? <capture>? <reg> ('|' ...)*
** -
** name: (optionnal)
**   '#{' <name> '}'	name a reg
**   '##{' <name> '}'	name a reg, the current reg is not used for matching
** -
** flags: (optionnal, cumulable)
**   '!'				not
**   'i'				ignore case (assume the reg is in lower case)
**                      TODO: i flag for groups
**   '='				lookahead assertion
**   '-'				non-greedy search
** -
** n: (optionnal, default: '1,1')
**   '?'				0,1
**   '*'				0,
**   '+'				1,
**   <n>				n,n
**   ','				+
**   <n> ','			match n or more times
**   ',' <m>			1,m
**   <n> ',' <m>		match n to m times
**   n and m are positive integer
** -
** capture: (optionnal)
**   '&' <index>?		save matched sub string
** -
** reg:
**   '.'				class IS_PRINT				{:print:}
**   TODO: 'p'			class IS_PRINT				{:print:}
**   TODO: 't'			class IS_PUNCT				{:punct:}
**   'a'				class IS_ALPHA [a-zA-Z]		{:alpha:}
**   'l'				class IS_LOWER [a-z]		{:lower:}
**   'u'				class IS_UPPER [A-Z]		{:upper:}
**   'd'				class IS_DIGIT [0-9]		{:digit:}
**   'n'				class IS_ALNUM [a-zA-Z0-9]	{:alnum:}
**   's'				class IS_SPACE [ \t]		{:space:}
**   'w'				class IS_WORD  [a-zA-Z0-9_]	{:word:}
**   TODO: 'h'			class          [a-zA-Z_]	{:head:}
**   TODO: 'x'			class          [a-fA-F0-9]	{:xdigit:}
**   'b'				word boundary
**   '^'				start of line (or string)
**   '$'				end of line (or string)
**   "'" <str> "'"		string
**   '"' <str> '"'		string
**   '[' <set> ']'		char set
**   '(' <regex> ')'	sub regex
**   '{' <name> '}'		use a named regex
**   '{:' <class>* '}'	join multiple class
**   TODO: '{:' <name> ':}'	fullname class
**   '{&' <index> '}'	match the content of a capture (or input)
*/

/*
** ========================================================================== **
** Regex match
*/

/*
** Store match result
** -
** 'str'		Input string
** 'match'		Match sub string (should be initialized with SUB(str.str, 0))
** 'captures'	Capture array (t_sub)
** 'capture_count'		Size of the 'captures' array
** 'lookahead_extra'	Character after the end of 'str' for lookahead assertion
** 'flags'		Flags:
** 			RMATCH_F_SEARCH		Allow unmatched character between matchs
** 			TODO: RMATCH_F_NBOL		'?^' will not match at the begin of the string
** 			TODO: RMATCH_F_NEOL		'?$' will not match at the end of the string
** 			TODO: RMATCH_F_ICASE	global ignore case
** -
** 'str' should not be modified between call to ft_rmatch
*/

struct		s_rmatch
{
	t_sub		str;
	t_sub		match;
	t_sub		*captures;
	uint32_t	capture_count;
	uint32_t	lookahead_extra;
	uint32_t	flags;
};

# define RMATCH_F_SEARCH	(1 << 0)

/*
** Test a string
** Return true on success, false on fail
*/
bool		ft_rmatch(t_rmatch *rmatch, t_regex const *regex);

/*
** ========================================================================== **
** Regex object
*/

struct		s_regex
{
	t_reg		*reg;
	uint32_t	capture_count;
};

struct		s_regex_err
{
	t_sub		str;
	uint32_t	offset;
};

/*
** Compile a regex
** Return true otherwise or false on error
** On error, 'err' is fill with error data
** 'err' can be NULL
*/
bool		ft_rcompile(t_regex *dst, t_sub pattern, t_regex_err *err);

/*
** Free a regex
** (Do not free the 'regex' pointer)
*/
void		ft_rdestroy(t_regex *regex);

#endif
