/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 22:10:54 by juloo             #+#    #+#             */
/*   Updated: 2015/06/24 22:51:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DSTR_H
# define FT_DSTR_H

# include "libft.h"

/*
** ========================================================================== **
** dstr
** ----
** Represent a (dynamic) string
** ----
** t_dstr._		contains private field
** t_dstr.sub	a sub representation of the string
** ----
** No memory is allocated if capacity is <= 0
** literal "" is used as default string
** Capacity field does not count the terminating '\0'
** ----
** Any 'length', 'index', 'from' or 'to' arguments follow this rule:
** If length is negative then: length = length + str_len + 1
*/

typedef struct	s_dstr
{
	char			*str;
	int				length;
	int				capacity;
}				t_dstr;

# define DSTR_MIN		16

# define DSTR_NEED(d,n)	(((d)->length + (n)) > (d)->capacity)

# define DSTRC(s)		((t_dstr){(s), sizeof(s) - 1, 0})
# define DSTR0()		((t_dstr){"", 0, 0})

# define SUBC(s)		SUB(s, sizeof(s) - 1)

# define DBEGIN(d)		((d)->str)
# define DEND(d)		((d)->str + (d)->length)

/*
** ft_dstr
** ----
** Create a dstr
** ----
** The resulting dstr contains allocated data
** ----
** Return a dstr
*/
t_dstr			ft_dstr(char const *src, int length);

/*
** ft_dstradd
** ----
** Add a string fragment to the dstr
*/
void			ft_dstradd(t_dstr *str, char const *add, int length);

/*
** ft_aprintf
** ----
** Process the format sequence using ft_printf rules
** and return it's result into a dstr
** ----
** Return a dstr
*/
t_dstr			ft_aprintf(char const *format, ...);

/*
** ft_asprintf
** ----
** Like ft_aprintf but the result is added to 'dst'
** ----
** Return the number of char added
*/
int				ft_asprintf(t_dstr *dst, char const *format, ...);

/*
** ft_dstradd_{char,nchar,sub}
** ----
** ft_dstradd_char		Add a char
** ft_dstradd_nchar		Add a char 'n' time
** ft_dstradd_sub		Add a sub string
*/
void			ft_dstradd_char(t_dstr *str, char c);
void			ft_dstradd_nchar(t_dstr *str, char c, int n);
void			ft_dstradd_sub(t_dstr *str, t_sub sub);

/*
** ft_dstradd_{int,uint,long,ulong}
** ----
** Add a representation of an integer to the dstr
** ----
** NOT IMPLEMENTED
*/
void			ft_dstradd_int(t_dstr *str, int nb);
void			ft_dstradd_uint(t_dstr *str, t_uint nb);
void			ft_dstradd_long(t_dstr *str, t_long nb);
void			ft_dstradd_ulong(t_dstr *str, t_long nb);

/*
** ft_dstrsub
** ----
** Create a sub from a dstr
** ----
** Return a sub
*/
t_sub			ft_dstrsub(t_dstr *str, int from, int to);

/*
** ft_dstrset
** ----
** Replace a part of string with an other
*/
void			ft_dstrset(t_dstr *str, int from, int to, t_sub sub);

/*
** ft_dstrpop
** ----
** Remove char from the end of the string
** ----
** Ex: a length of -1 will clear the dstr
*/
void			ft_dstrpop(t_dstr *str, int length);

/*
** ft_dstrextend
** ----
** Test if the string can store 'need' more chars
** Extend the alloc if needed
*/
void			ft_dstrextend(t_dstr *str, int need);

/*
** ft_dstrdestroy
** ----
** Free allocated memory
** The dstr is still usable
*/
void			ft_dstrdestroy(t_dstr *str);

/*
** ft_dstrfree
** ----
** Reduce capacity to fit real length
** ----
** NOT IMPLEMENTED
*/
void			ft_dstrfree(t_dstr *str);

#endif
