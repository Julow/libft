/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:25:52 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 22:28:30 by juloo            ###   ########.fr       */
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
	uint32_t		i;

	if (m->len - offset > reg->str.length)
	{
		if (reg->reg.flags & REG_F_ICASE)
		{
			if (!ft_subequi(SUB(m->str + offset, reg->str.length), reg->str))
				return(REG_FAIL);
		}
		else if (ft_memcmp(m->str + offset, reg->str.str, reg->str.length) != 0)
			return (REG_FAIL);
	}
	return (offset + reg->str.length);
}
