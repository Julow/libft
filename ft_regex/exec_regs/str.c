/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2016/01/02 17:59:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

// TODO: move to ft::sub module
bool			ft_subequi(t_sub a, t_sub b)
{
	uint32_t		i;

	if (a.length != b.length)
		return (false);
	i = 0;
	while (i < a.length)
	{
		if (LOWER(a.str[i]) != LOWER(b.str[i]))
			return (false);
		i++;
	}
	return (true);
}

uint32_t		exec_reg_str(t_rmatch *m, t_reg_str const *reg, uint32_t offset)
{
	if (BOOL_OF(m->len - offset >= reg->str.length
			&& ((reg->reg.flags & REG_F_ICASE && ft_subequi(SUB(m->str + offset,
				reg->str.length), reg->str))
			|| ft_memcmp(m->str + offset, reg->str.str, reg->str.length) == 0))
		^ BOOL_OF(reg->reg.flags & REG_F_NOT))
		return (offset + reg->str.length);
	return (REG_FAIL);
}
