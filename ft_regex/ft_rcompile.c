/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rcompile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:18:40 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 20:18:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"
#include <stdlib.h>

static void		destroy_parser(t_parse_reg *p)
{
	t_parse_reg_n	*n;
	t_parse_reg_n	*tmp;

	n = p->named_regs;
	while (n != NULL)
	{
		tmp = n;
		n = n->prev;
		free(tmp);
	}
}

bool			ft_rcompile(t_regex *dst, t_sub pattern)
{
	t_reg			**tmp;
	uint32_t		offset;
	uint32_t		start;
	t_parse_reg		parser;

	offset = 0;
	dst->reg = NULL;
	tmp = &dst->reg;
	parser = (t_parse_reg){pattern.str, pattern.length, NULL};
	while (offset < parser.len)
	{
		start = offset;
		while (offset < parser.len && parser.str[offset] != '?')
			offset++;
		if (start == offset)
			offset = parse_reg(&parser, offset + 1, tmp);
		else
			*tmp = create_reg_str(SUB(parser.str + start, offset - start));
		if (offset == REG_FAIL)
			return (destroy_reg(dst->reg), destroy_parser(&parser), false);
		tmp = &(*tmp)->next;
	}
	destroy_parser(&parser);
	return (true);
}
