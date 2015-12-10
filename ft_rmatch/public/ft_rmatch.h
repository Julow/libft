/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmatch.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 17:11:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:14:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RMATCH_H
# define FT_RMATCH_H

# include "ft/libft.h"

/*
** ========================================================================== **
** Regex
** ---
** ?<opt><n><match>
** ?<opt><n><match>|<opt><n><match>| ...
** ---
** opt: (cummulable but need to be in this order)
** - !		Match not (invert matching)
** - i		Lower case (str is treated as lower, match need to be lower case)
** ---
** n:
** - 1		Match 1 (Default)
** - ?		Match 0 or 1
** - *		Match 0 or more
** - +		Match 1 or more
** - n		Match n
** - n,		Match n or more
** - n,N	Match n to N
** ---
** match:
** - .		Match any char (except '\0')
** - w		ft_isword		[a-zA-Z0-9_]
** - a		ft_isalpha		[a-zA-Z]
** - n		ft_isalnum		[a-zA-Z0-9]
** - c		ft_isascii		.
** - d		ft_isdigit		[0-9]
** - p		ft_isprint		[ -~]
** - s		ft_isspace		[ \t]
** - h		ft_iswhite		[ \t\n\r\v\f]
** - :a		Match a char
** - &i		Match a valid int
** - [abc]	Match a set of char
** - [a-z]	Match an interval of char (cummulable with char set)
** - 'abc'	Match a string
** - (abc)	Match a string (can contains regex)
** ---
** TODO:
** - global lower case mode (?i;)
** - str end (?$)
** - sprintf like parsing (using va_arg)
** ---
*/

bool			ft_rmatch(const char *str, const char *pattern);
int				ft_rtest(const char *str, const char *pattern);
bool			ft_rfind(t_sub *dst, const char *str, const char *pattern);
bool			ft_rnext(t_sub *last, const char *pattern);

int				ft_matchint(const char *str);

#endif
