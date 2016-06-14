/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 22:10:54 by juloo             #+#    #+#             */
/*   Updated: 2016/06/14 14:44:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DSTR_H
# define FT_DSTR_H

# include "ft/libft.h"

typedef struct s_dstr	t_dstr;

/*
** ========================================================================== **
** Dynamic string
** ----
** No memory is allocated if capacity is <= 0
** Capacity field does not count the terminating '\0'
*/

struct			s_dstr
{
	char			*str;
	uint32_t		length;
	uint32_t		capacity;
};

/*
** DSTR_NEED(D+, N)		Check if the string can store N char without extending
** DSTR_EXTEND(D+, N+)	Extend the string if needed
** DSTR_APPEND(D+, C)	Append a char to the dstr (Does not put the '\0')
** DSTR(STR, LEN)		Construct a dstr from a const string
** DSTRC(STR)			Construct a dstr from a c string
** DSTR0()				Construct an empty dstr
** DSTR_SUB(DSTR)		Construct a sub from a dstr
*/

# define DSTR_NEED(D, N)	(((D)->length + (N) + 1) > (D)->capacity)

# define DSTR_EXTEND(D, N)	(DSTR_NEED(D, N) ? ft_dstrextend(D, N) : (void)0)

# define DSTR_APPEND(D, C)	(DSTR_EXTEND(D, 1), (D)->str[(D)->length++] = (C))

# define DSTR(STR,LEN)		((t_dstr){(STR), (LEN), 0})
# define DSTRC(STR)			((t_dstr){(STR), sizeof(STR) - 1, 0})
# define DSTR0()			((t_dstr){"", 0, 0})

/*
** TODO: type safety
*/
# define DSTR_SUB(DSTR)		(*(t_sub const*)(&(DSTR)))

/*
** ft_dstradd
** ----
** Add a sub to the dstr
** (Care about the terminating '\0')
*/
void			ft_dstradd(t_dstr *str, t_sub add);

/*
** ft_dstrspan
** ----
** Change the size of a span ('from', 'to') to ('from', 'from' + 'size')
** -
** Can be used to remove/insert characters
** (Care about the terminating '\0')
** -
** if 'from' or 'to' are negative then str->length + 1 is added to it
** -1 mean str->length
** -2 mean str->length -1
** 'from' and 'to' are swaped if 'from' > 'to'
** ----
** Return a pointer to the start of the span
*/
char			*ft_dstrspan(t_dstr *str, int from, int to, int size);

/*
** ft_dstrextend
** ----
** Test if the string can store 'need' more chars
** Extend the alloc if needed
*/
void			ft_dstrextend(t_dstr *str, uint32_t need);

/*
** ft_dstrclear
** ----
** Free allocated memory
** The dstr is still usable
*/
void			ft_dstrclear(t_dstr *str);

/*
** -
*/
# define DSTR_MIN			16

#endif
