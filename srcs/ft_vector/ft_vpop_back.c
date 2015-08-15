/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 18:30:33 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 23:41:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

void			ft_vpop_back(t_vector *v, void *data)
{
	if (v->last == NULL)
		return ;
	v->last->end -= v->element_size;
	v->length--;
	if (data != NULL)
		ft_memcpy(data, VEC_C_DATA(v->last) + v->last->end, v->element_size);
	if (v->last->start >= v->last->end)
		vector_c_del(v, v->last);
}
