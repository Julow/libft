/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_out.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 22:31:01 by juloo             #+#    #+#             */
/*   Updated: 2015/12/05 17:26:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STROUT_H
# define FT_STROUT_H

# include "libft.h"
# include "ft_out.h"

/*
** ========================================================================== **
** String out
*/

typedef t_out		t_str_out;

# define STR_OUT()		(OUT("", 0, &ft_str_out_flush))

/*
** Return a sub of the buffer
*/
t_sub			ft_str_out_sub(t_str_out const *out);

/*
** Free the buffer
*/
void			ft_str_out_clear(t_str_out *out);

/*
** Flush (used by ft::out)
*/
void			ft_str_out_flush(t_str_out *out);

#endif
