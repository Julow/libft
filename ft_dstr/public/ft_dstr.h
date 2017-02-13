/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 22:10:54 by juloo             #+#    #+#             */
/*   Updated: 2017/02/13 14:58:29 by jaguillo         ###   ########.fr       */
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

# define DSTR_SUB(DSTR)		(*(t_sub const*)(&(DSTR)))

/*
** ft_dstradd
** -
** Add a sub to the dstr
** (Care about the terminating '\0')
*/
void			ft_dstradd(t_dstr *str, t_sub add);

/*
** ft_dstrspan
** -
** Change the size of the span ('from', 'to') to ('from', 'from' + 'size')
** -
** If 'src' is not NULL, 'size' characters are copied from it to the span
** -
** Can be used to remove/insert characters
** (Care about the terminating '\0')
** -
** Return a pointer to the start of the span
*/
char			*ft_dstrspan(t_dstr *str, uint32_t from, uint32_t to,
					char const *src, uint32_t size);

/*
** ft_dstrextend
** -
** Test if the string can store 'need' more chars
** Extend the alloc if needed
*/
void			ft_dstrextend(t_dstr *str, uint32_t need);

/*
** ft_dstrclear
** -
** Free allocated memory
** The dstr is still usable
*/
void			ft_dstrclear(t_dstr *str);

/*
** -
*/
# define DSTR_MIN			16

#endif
