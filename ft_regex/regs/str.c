/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:10:32 by juloo             #+#    #+#             */
/*   Updated: 2015/12/26 20:33:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		parse_reg_str(t_sub pattern, uint32_t offset, t_reg **reg)
{
	char const		quote = pattern.str[offset];
	uint32_t const	start = ++offset;

	while (offset < pattern.length && pattern.str[offset] != quote)
		offset++;
	if (offset >= pattern.length)
		return (REG_FAIL);
	*reg = create_reg_str(SUB(pattern.str + start, offset - start));
	return (offset + 1);
}
