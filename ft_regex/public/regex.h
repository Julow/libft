/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:56:34 by juloo             #+#    #+#             */
/*   Updated: 2016/01/04 01:04:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_H
# define REGEX_H

# include "ft/libft.h"

typedef struct s_regex			t_regex;
typedef struct s_regex_err		t_regex_err;
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
** capture: (optionnal)
**   '&' <index>?		save matched sub string
** -
** reg:
**   '.'				is IS_PRINT [ -~]
**   'a'				is IS_ALPHA [a-zA-Z]
**   'l'				is IS_LOWER [a-z]
**   'u'				is IS_UPPER [A-Z]
**   'd'				is IS_DIGIT [0-9]
**   'n'				is IS_ALNUM [a-zA-Z0-9]
**   's'				is IS_SPACE [ \t]
**   'w'				is IS_WORD  [a-zA-Z0-9_]
**   'b'				word boundary
**   '^'				start of line (or string)
**   '$'				end of line (or string)
**   "'" <str> "'"		string
**   '"' <str> '"'		string
**   '[' <set> ']'		char set
**   '(' <regex> ')'	sub regex
**   '{' <name> '}'		use a named regex
**   '{:' <is>* '}'		join multiple is regs
**   '{&' <index> '}'	match the content of a capture (or input)
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
** Test a string
** 'match' should be initialized with SUB(str.str, 0)
** 'c' is where captures are saved (can be NULL)
** Return true on success, false on fail
** 'c' have to be of size of 'regex->capture_count' t_subs or NULL
*/
bool		ft_rmatch(t_sub str, t_sub *match, t_regex const *regex, t_sub *c);

/*
** Like ft_rmatch but allow unmatched char between matchs
*/
bool		ft_rsearch(t_sub str, t_sub *match, t_regex const *regex, t_sub *c);

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
