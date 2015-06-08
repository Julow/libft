/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 22:10:54 by juloo             #+#    #+#             */
/*   Updated: 2015/06/09 01:05:25 by juloo            ###   ########.fr       */
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

typedef union	u_dstr
{
	struct
	{
		char		*str;
		int			length;
		int			capacity;
	}			_;
	struct
	{
		char *const	str;
		const int	length;
		const int	capacity;
	};
	const t_sub		sub;
}				t_dstr;

# define DSTR_MIN		16

# define DSTR_NEED(d,n)	(((d)->length + (n)) > (d)->capacity)

// Create a dstr from a literal string
# define DSTRC(s)		((t_dstr){(s), sizeof(s) - 1, 0})
// Create an empty dstr
# define DSTR0()		((t_dstr){"", 0, 0})

# define SUBC(s)		SUB(s, sizeof(s) - 1)

/*
** ft_dstr
** ----
** Create a dstr
** ----
** The resulting dstr contains allocated data
** ----
** Return a dstr
*/
static t_dstr	ft_dstr(char const *src, int length)
{
	t_dstr			dstr;

	if (length < 0)
		length += ft_strlen(src) + 1;
	dstr._.length = length;
	dstr._.capacity = MAX(length, DSTR_MIN);
	dstr._.str = MAL(char, dstr._.capacity + 1);
	ft_memcpy(dstr._.str, src, length);
	dstr._.str[length] = '\0';
	return (dstr);
}

/*
** ft_dstradd
** ----
** Add a string fragment to the dstr
*/
static void		ft_dstradd(t_dstr *str, char const *add, int length)
{
	if (length < 0)
		length += ft_strlen(add) + 1;
	if (DSTR_NEED(str, length))
		ft_dstrextend(str, length);
	ft_memcpy(str->_.str + str->_.length, add, length);
	str->_.length += length;
	str->_.str[str->_.length] = '\0';
}

void			ft_dstradd_int(t_dstr *str, int nb);
void			ft_dstradd_uint(t_dstr *str, t_uint nb);
void			ft_dstradd_long(t_dstr *str, t_long nb);
void			ft_dstradd_ulong(t_dstr *str, t_long nb);

void			ft_dstradd_char(t_dstr *str, char c);
void			ft_dstradd_nchar(t_dstr *str, char c, int n);
void			ft_dstradd_sub(t_dstr *str, t_sub sub);

/*
** ft_dstrsub
** ----
** Create a sub from a dstr
** ----
** Return a sub
*/
static t_sub	ft_dstrsub(t_dstr *str, int from, int to)
{
	if (from < 0)
		from += str->length + 1;
	if (to < 0)
		to += str->length + 1;
	return (SUB(str->str + from, to - from));
}

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
static void		ft_dstrpop(t_dstr *str, int length)
{
	if (length < 0)
		length += str->length + 1;
	str->_.length -= length;
	str->_.str[str->_.length] = '\0';
}

/*
** ft_dstrextend
** ----
** Test if the string can store 'extend' char
** Extend the alloc if needed
*/
void			ft_dstrextend(t_dstr *str, int extend);

/*
** ft_dstrfree
** ----
** Reduce capacity to fit real length
*/
void			ft_dstrfree(t_dstr *str);

#endif
