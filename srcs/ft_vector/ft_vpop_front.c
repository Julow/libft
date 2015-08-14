/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpop_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 19:59:06 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 20:25:35 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

void			ft_vpop_front(t_vector *v, void *data)
{
	if (data != NULL)
		ft_memcpy(data, VEC_C_DATA(v->first) + v->first->start,
			v->element_size);
	v->first->start += v->element_size;
	v->length--;
	if (v->first->start >= v->first->end)
		vector_c_del(v, v->first);
}
