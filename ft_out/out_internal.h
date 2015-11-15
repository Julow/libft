/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:34 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 14:38:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUT_INTERNAL_H
# define OUT_INTERNAL_H

# include "ft_out.h"

# define SHOULD_TRANSFORM(FLAGS)	((FLAGS) & OUT_TOLOWER | OUT_TOUPPER)

# define WRITE_INT_BUFF				(64 + 1 + 6 + 1)
# define WRITE_FLOAT_BUFF			(128)

# define DEF_PRECI					6

/*
** Write str
*/
void			out_writestr(t_out *out, char const *str, uint32_t len);

/*
** Write n time 'c'
*/
void			out_writenchar(t_out *out, char c, uint32_t n);

/*
** Apply left width
*/
void			out_before(t_out *out, int32_t len);

/*
** Apply right width
** reset fill, width, OUT_TOLOWER, OUT_TOUPPER, OUT_CENTER
*/
void			out_after(t_out *out, int32_t len);

/*
** Apply OUT_TOLOWER, OUT_TOUPPER and OUT_REVCASE
*/
void			out_transform(int flags, char *str, uint32_t len);

#endif
