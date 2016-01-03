/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:10:32 by juloo             #+#    #+#             */
/*   Updated: 2016/01/03 15:10:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		parse_reg_str(t_parse_reg *p, uint32_t offset, t_reg **reg)
{
	char const		quote = p->str[offset];
	uint32_t const	start = ++offset;

	while (offset < p->len && p->str[offset] != quote)
		offset++;
	if (offset >= p->len)
		return (REG_ERROR(p, "Unclosed string", start));
	*reg = create_reg_str(SUB(p->str + start, offset - start));
	return (offset + 1);
}
