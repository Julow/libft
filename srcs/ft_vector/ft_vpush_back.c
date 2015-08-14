/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 16:38:02 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 17:34:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

void			*ft_vpush_back(t_vector *v, void *data)
{
	void			*dst;

	if (v->last == NULL || (v->last->end + v->element_size) > VEC_C_SIZE)
		vector_c_after(v, v->last);
	dst = VEC_C_DATA(v->last) + v->last->end;
	v->last->end += v->element_size;
	v->length++;
	if (data == NULL)
		ft_bzero(dst, v->element_size);
	else
		ft_memcpy(dst, data, v->element_size);
	return (dst);
}
