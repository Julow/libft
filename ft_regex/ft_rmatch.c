/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 10:58:38 by juloo             #+#    #+#             */
/*   Updated: 2016/01/03 22:35:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

#define RMATCH(STR,R,C)	((t_rmatch){(STR).str, (STR).length, (C), _RMATCH(R,C)})
#define _RMATCH(R,C)	(((C) == NULL) ? 0 : (R)->capture_count)

static bool	rmatch(t_rmatch *r, t_sub *match, t_reg const *reg, bool search)
{
	uint32_t		offset;
	uint32_t		tmp;

	offset = match->str + match->length - r->str;
	while (offset < r->len)
	{
		tmp = exec_reg(r, reg, offset);
		if (tmp != REG_FAIL && tmp > offset)
		{
			*match = SUB(r->str + offset, tmp - offset);
			return (true);
		}
		if (!search)
			break ;
		offset++;
	}
	*match = SUB(r->str + offset, 0);
	return (false);
}

bool		ft_rmatch(t_sub str, t_sub *match, t_regex const *regex, t_sub *c)
{
	t_rmatch		r;

	r = RMATCH(str, regex, c);
	return (rmatch(&r, match, regex->reg, false));
}

bool		ft_rsearch(t_sub str, t_sub *match, t_regex const *regex, t_sub *c)
{
	t_rmatch		r;

	r = RMATCH(str, regex, c);
	return (rmatch(&r, match, regex->reg, true));
}
