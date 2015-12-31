/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:56:34 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 22:24:13 by juloo            ###   ########.fr       */
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
**   '!'				not						TODO: match
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
**   '.'				IS_PRINT
**   'a'				IS_ALPHA
**   'l'				IS_LOWER
**   'u'				IS_UPPER
**   'd'				IS_DIGIT
**   'n'				IS_ALNUM
**   's'				IS_SPACE
**   'w'				IS_WORD
**   '<' <is>* '>'		OR multiple IS_*
**   'b'				word boundary
**   '$'				end of string
**   "'" <str> "'"		string
**   '"' <str> '"'		string
**   '[' <set> ']'		char set
**   '(' <regex> ')'	sub regex
**   '{' <name> '}'		use a named regex
** -
** TODO: start of string (?^)
*/

struct			s_regex
{
	t_reg			*reg;
	uint32_t		capture_count;
};

/*
** Compile a regex
** Return true otherwise or false on error
*/
bool			ft_rcompile(t_regex *dst, t_sub pattern);

/*
** Test a string
** Return the number of char that match
** 'captures' have to be of size of 'regex->capture_count' t_subs or NULL
*/
uint32_t		ft_rmatch(t_sub str, t_regex const *regex, t_sub *captures);

/*
** Free a regex
** (Do not free the 'regex' pointer)
*/
void			ft_rdestroy(t_regex *regex);

#endif
