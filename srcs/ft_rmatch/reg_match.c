/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:13:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/21 23:31:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

static void		skip_or(const char **pattern)
{
	t_reg			tmp;

	while (**pattern == '|')
		*pattern = reg_parse(&tmp, *pattern + 1);
}

const char		*reg_match(const char *str, const char **pattern)
{
	t_reg			reg;
	char const		*tmp;

	*pattern = reg_parse(&reg, (*pattern) + 1);
	if (**pattern == '|')
	{
		if ((tmp = reg_match(str, pattern)) != NULL)
			return (tmp);
		skip_or(pattern);
	}
	return (reg_reg(&reg, str, *pattern, 0));
}
