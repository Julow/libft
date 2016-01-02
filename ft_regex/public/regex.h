/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:56:34 by juloo             #+#    #+#             */
/*   Updated: 2016/01/02 20:06:01 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_H
# define REGEX_H

# include "ft/libft.h"

typedef struct s_regex			t_regex;
typedef struct s_reg			t_reg;

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
** capture: (optionnal)							TODO: parse, match
**   '&' <index>?		save matched sub string
** -
** reg:
**   '.'				IS_PRINT [ -~]
**   'a'				IS_ALPHA [a-zA-Z]
**   'l'				IS_LOWER [a-z]
**   'u'				IS_UPPER [A-Z]
**   'd'				IS_DIGIT [0-9]
**   'n'				IS_ALNUM [a-zA-Z0-9]
**   's'				IS_SPACE [ \t]
**   'w'				IS_WORD  [a-zA-Z0-9_]
**   '<' <IS>* '>'		join multiple IS_*
**   'b'				word boundary
**   '^'				start of string
**   '$'				end of string
**   "'" <str> "'"		string
**   '"' <str> '"'		string
**   '[' <set> ']'		char set
**   '(' <regex> ')'	sub regex
**   '{' <name> '}'		use a named regex
** -
** TODO: start of string (?^)
*/

struct		s_regex
{
	t_reg		*reg;
	uint32_t	capture_count;
};

/*
** Test a string
** 'match' should be initialized with SUB(str.str, 0)
** 'c' is where captures are saved (can be NULL)
** Return true on success, false on fail
** 'c' have to be of size of 'regex->capture_count' t_subs or NULL
*/
bool		ft_rmatch(t_sub str, t_sub *match, t_regex const *regex, t_sub *c);

/*
** Compile a regex
** Return true otherwise or false on error
*/
bool		ft_rcompile(t_regex *dst, t_sub pattern);

/*
** Free a regex
** (Do not free the 'regex' pointer)
*/
void		ft_rdestroy(t_regex *regex);

#endif
