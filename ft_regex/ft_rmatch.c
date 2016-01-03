/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 10:58:38 by juloo             #+#    #+#             */
/*   Updated: 2016/01/03 18:34:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

bool		ft_rmatch(t_sub str, t_sub *match, t_regex const *regex, t_sub *c)
{
	t_rmatch		rmatch;
	uint32_t		offset;
	uint32_t		tmp;

	rmatch = (t_rmatch){str.str, str.length, c,
		(c == NULL) ? 0 : regex->capture_count};
	offset = match->str + match->length - str.str;
	while (offset < str.length)
	{
		tmp = exec_reg(&rmatch, regex->reg, offset);
		if (tmp != REG_FAIL && tmp > offset)
		{
			*match = SUB(str.str + offset, tmp - offset);
			return (true);
		}
		offset++;
	}
	*match = SUB(str.str + offset, 0);
	return (false);
}
