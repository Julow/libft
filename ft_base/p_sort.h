/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sort.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 17:12:57 by juloo             #+#    #+#             */
/*   Updated: 2016/08/27 17:13:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_SORT_H
# define P_SORT_H

# include "ft/libft.h"

typedef struct s_sort_data		t_sort_data;

/*
** ========================================================================== **
*/

struct			s_sort_data
{
	void			*data;
	int				(*cmp)(void const *data, uint32_t a, uint32_t b);
	void			(*swap)(void *data, uint32_t a, uint32_t b);
};

#endif
