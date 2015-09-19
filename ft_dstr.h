/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 22:10:54 by juloo             #+#    #+#             */
/*   Updated: 2015/09/19 11:23:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DSTR_H
# define FT_DSTR_H

# include "libft.h"

/*
** ========================================================================== **
** Dynamic string
** ----
** No memory is allocated if capacity is <= 0
** literal "" is used as default string
** Capacity field does not count the terminating '\0'
*/

struct			s_dstr
{
	char			*str;
	int				length;
	int				capacity;
};

# define DSTR_MIN		16

# define DSTR_NEED(d,n)	(((d)->length + (n)) > (d)->capacity)

# define DSTR(s,l)		((t_dstr){(s), (l), 0})
# define DSTRC(s)		((t_dstr){(s), sizeof(s) - 1, 0})
# define DSTR0()		((t_dstr){"", 0, 0})

# define DBEGIN(d)		((d)->str)
# define DEND(d)		((d)->str + (d)->length)

/*
** ft_dstradd
** ----
** Add a sub to the dstr
*/
void			ft_dstradd(t_dstr *str, t_sub add);

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
void			ft_dstrextend(t_dstr *str, int need);

/*
** ft_dstrclear
** ----
** Free allocated memory
** The dstr is still usable
*/
void			ft_dstrclear(t_dstr *str);

#endif
