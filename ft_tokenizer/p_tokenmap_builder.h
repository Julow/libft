/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tokenmap_builder.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 19:11:16 by juloo             #+#    #+#             */
/*   Updated: 2016/08/27 19:11:42 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_TOKENMAP_BUILDER_H
# define P_TOKENMAP_BUILDER_H

# include "ft/libft.h"
# include "ft/tokenmap_builder.h"

typedef struct s_tokenmap_b_t		t_tokenmap_b_t;

/*
** ========================================================================== **
*/

struct			s_tokenmap_b_t
{
	t_sub			str;
	void const		*data;
};

#endif
