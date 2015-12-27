/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rcompile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:18:40 by juloo             #+#    #+#             */
/*   Updated: 2015/12/27 17:38:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

bool			ft_rcompile(t_regex *dst, t_sub pattern)
{
	t_reg			**tmp;
	uint32_t		offset;
	uint32_t		start;

	offset = 0;
	dst->reg = NULL;
	tmp = &dst->reg;
	while (offset < pattern.length)
	{
		start = offset;
		while (offset < pattern.length && pattern.str[offset] != '?')
			offset++;
		if (start == offset)
			offset = parse_reg(pattern, offset + 1, tmp);
		else
			*tmp = create_reg_str(SUB(pattern.str + start, offset - start));
		if (offset == REG_FAIL)
			return (destroy_reg(dst->reg), false);
		tmp = &(*tmp)->next;
	}
	return (true);
}
