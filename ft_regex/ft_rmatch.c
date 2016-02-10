/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 10:58:38 by juloo             #+#    #+#             */
/*   Updated: 2016/02/10 17:36:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

bool		ft_rmatch(t_rmatch *rmatch, t_regex const *regex)
{
	uint32_t	offset;
	uint32_t	tmp;

	offset = rmatch->match.str + rmatch->match.length - rmatch->str.str;
	while (offset < rmatch->str.length)
	{
		tmp = exec_reg(rmatch, regex->reg, offset);
		if (tmp != REG_FAIL && tmp > offset)
		{
			rmatch->match = SUB(rmatch->str.str + offset, tmp - offset);
			return (true);
		}
		if (!(rmatch->flags & RMATCH_F_SEARCH))
			break ;
		offset++;
	}
	rmatch->match = SUB(rmatch->str.str + offset, 0);
	return (false);
}
