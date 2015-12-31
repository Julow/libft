/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:11:27 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 21:23:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

t_reg			*append_reg_next(t_reg *reg, t_reg *next)
{
	while (reg != NULL)
	{
		reg->next = next;
		reg = reg->or_next;
	}
	return (next);
}

t_reg			*create_reg_str(t_sub str)
{
	t_reg_str *const	r = ft_emalloc(sizeof(t_reg_str) + str.length);

	ft_memcpy(ENDOF(r), str.str, str.length);
	r->str = SUB(ENDOF(r), str.length);
	r->reg.type = REG_T_STR;
	r->reg.min = 1;
	r->reg.max = 1;
	r->reg.flags = 0;
	r->reg.or_next = NULL;
	r->reg.next = NULL;
	return (V(r));
}
