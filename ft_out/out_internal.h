/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:34 by juloo             #+#    #+#             */
/*   Updated: 2016/03/01 23:32:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUT_INTERNAL_H
# define OUT_INTERNAL_H

# include "ft/ft_out.h"

# define SHOULD_TRANSFORM(FLAGS)	((FLAGS) & (OUT_TOLOWER | OUT_TOUPPER))

# define WRITE_INT_BUFF				(64 + 1 + 6 + 1)
# define WRITE_FLOAT_BUFF			(128)

# define DEF_PRECI					6

/*
** Apply OUT_TOLOWER, OUT_TOUPPER and OUT_REVCASE
*/
void			out_transform(int flags, char *str, uint32_t len);

#endif
