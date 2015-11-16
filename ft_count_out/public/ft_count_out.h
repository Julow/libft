/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_out.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 22:40:19 by juloo             #+#    #+#             */
/*   Updated: 2015/11/16 22:51:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COUNT_OUT_H
# define FT_COUNT_OUT_H

# include "ft_out.h"
# include <stdint.h>

typedef struct s_count_out	t_count_out;

/*
** ========================================================================== **
** Count out
** -
** Does not output characters, instead it count them
*/

struct s_count_out
{
	t_out		out;
	uint32_t	count;
};

/*
** Create a count_out
*/
# define COUNT_OUT()		((t_count_out){OUT(g_countout_buff, COUNT_OUT_BUFF, &count_out_flush), 0})

/*
** -
*/

void			count_out_flush(t_count_out *out);

extern char		g_countout_buff[];

# define COUNT_OUT_BUFF		128

#endif
