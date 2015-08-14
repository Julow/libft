/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 18:21:59 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 18:24:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdlib.h>

void			ft_vclear(t_vector *v)
{
	t_vec_c			*next;
	t_vec_c			*tmp;

	next = v->first;
	while (next != NULL)
	{
		tmp = next;
		next = next->next;
		free(tmp);
	}
	v->length = 0;
	v->first = NULL;
	v->last = NULL;
}
