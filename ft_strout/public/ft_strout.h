/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strout.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 22:31:01 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 22:40:59 by juloo            ###   ########.fr       */
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

typedef t_out		t_strout;

# define STROUT()		(OUT("", 0, &ft_strout_flush))

/*
** Return a sub of the buffer
*/
t_sub			ft_strout_sub(t_strout const *out);

/*
** Free the buffer
*/
void			ft_strout_clear(t_strout *out);

/*
** Flush (used by ft::out)
*/
void			ft_strout_flush(t_strout *out);

#endif
