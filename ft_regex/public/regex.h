/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:56:34 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 18:25:35 by juloo            ###   ########.fr       */
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
**   'i'				ignore case
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
**   n and m are positive integer or:
**     TODO: '%' <index>?		take the value from va args
** -
** TODO: capture: (optionnal)
**   '&' <flags>? <index>?
**   write captured sub string to a t_sub* from va args
**   flags: (optionnal)
**     'f'				take a function from va args instead of t_sub*
**                      if the function return false, the match fail
**                      bool (*f)(t_sub, void*)
**     '*'				next argument is a void* and is passed to 'f'
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
**   ':' <index>? 's'	string (t_sub from va args)
**   ':' <index>? 'S'	string (char const* from va args)
**   ':' <index>? 'r'	sub regex (t_regex const* from va args)
**   "'" <str> "'"		string
**   '"' <str> '"'		string
**   '[' <set> ']'		char set
**   '(' <regex> ')'	sub regex
**   '{' <name> '}'		use a named regex
** -
** TODO: ft_rmatch
*/

struct			s_regex
{
	t_reg			*reg;
};

/*
** Compile a regex
** Return true otherwise or false on error
*/
bool			ft_rcompile(t_regex *dst, t_sub pattern);

/*
** Free a regex
** (Do not free the 'regex' pointer)
*/
void			ft_rdestroy(t_regex *regex);

#endif
