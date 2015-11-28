/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 18:21:59 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_deque.h"
#include <stdlib.h>

void			ft_qclear(t_deque *v)
{
	t_que_c			*next;
	t_que_c			*tmp;

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
