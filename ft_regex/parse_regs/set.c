/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:09:39 by juloo             #+#    #+#             */
/*   Updated: 2015/12/30 17:50:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		parse_reg_set(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	t_reg_set			*r;
	uint32_t			i;
	char				c;
	char				end;

	i = ++offset;
	while (offset < p->len && p->str[offset] != ']')
		offset++;
	if (offset >= p->len)
		return (REG_FAIL);
	r = MAL1(t_reg_set);
	ft_bzero(r, sizeof(t_reg_set));
	while (i < offset)
	{
		c = p->str[i++];
		if ((i + 2) < offset && p->str[i] == '-')
		{
			if (c < (end = p->str[++i]))
				ft_bitset(r->set, c, end - c);
			else
				ft_bitset(r->set, end, c - end);
			i++;
		}
		else
			BITARRAY_SET(r->set, c);
	}
	r->reg.type = REG_T_SET;
	*reg = V(r);
	return (offset + 1);
}