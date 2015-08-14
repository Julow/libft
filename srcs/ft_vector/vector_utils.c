/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 17:03:39 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 20:45:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"
#include <stdlib.h>

void			*vector_it_c(t_vector_it *it)
{
	while (it->data >= it->end)
	{
		if (it->next == NULL)
			return (NULL);
		it->data = VEC_C_DATA(it->next) + it->next->start;
		it->end = VEC_C_DATA(it->next) + it->next->end;
		it->next = it->next->next;
	}
	return (it->data);
}

void			vector_c_del(t_vector *v, t_vec_c *c)
{
	if (c == v->first)
		v->first = c->next;
	if (c == v->last)
		v->last = c->prev;
	if (c->next != NULL)
		c->next->prev = c->prev;
	if (c->prev != NULL)
		c->prev->next = c->next;
	free(c);
}

void			vector_c_after(t_vector *v, t_vec_c *c)
{
	t_vec_c			*after;

	after = (t_vec_c*)ft_emalloc(sizeof(t_vec_c) + VEC_C_SIZE);
	after->start = 0;
	after->end = 0;
	after->prev = c;
	if (c == NULL)
	{
		after->next = NULL;
		v->first = after;
		v->last = after;
	}
	else
	{
		after->next = c->next;
		if (c->next == NULL)
			v->last = after;
		else
			c->next->prev = c;
		c->next = after;
	}
}

void			vector_c_before(t_vector *v, t_vec_c *c)
{
	t_vec_c			*before;

	before = (t_vec_c*)ft_emalloc(sizeof(t_vec_c) + VEC_C_SIZE);
	before->start = VEC_C_SIZE;
	before->end = VEC_C_SIZE;
	before->next = c;
	if (c == NULL)
	{
		before->prev = NULL;
		v->first = before;
		v->last = before;
	}
	else
	{
		before->prev = c->prev;
		if (c->prev == NULL)
			v->first = before;
		else
			c->prev->next = c;
		c->prev = before;
	}
}
